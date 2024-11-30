// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianRepositoryReleaseFileTests.hpp"
#include "CodeSmithy/DebianRepositoryTools/DebianRepositoryReleaseFile.hpp"

using namespace CodeSmithy;

DebianRepositoryReleaseFileTests::DebianRepositoryReleaseFileTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "DebianRepositoryReleaseFile tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("write test 1", WriteTest1);
}

void DebianRepositoryReleaseFileTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianRepositoryReleaseFile release_file(Ishiko::UTCTime(Ishiko::Date(2024, 11, 29), Ishiko::TimeOfDay(0, 0, 0)));

    ISHIKO_TEST_PASS();
}

void DebianRepositoryReleaseFileTests::WriteTest1(Ishiko::Test& test)
{
    const char* output_name = "DebianRepositoryReleaseFileTests_WriteTest1";
    const boost::filesystem::path output_path = test.context().getOutputPath(output_name);

    const boost::filesystem::path packages_file_path = test.context().getDataPath("Packages");

    Ishiko::Error error;
    Ishiko::TextFile output_file;
    // TODO: create and use throwing variant of TextFile::Create
    output_file.create(output_path, error);

    DebianRepositoryReleaseFile release_file(Ishiko::UTCTime(Ishiko::Date(2024, 11, 29), Ishiko::TimeOfDay(0, 0, 0)));
    release_file.addFile(packages_file_path.string());

    release_file.write(output_file);

    output_file.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}
