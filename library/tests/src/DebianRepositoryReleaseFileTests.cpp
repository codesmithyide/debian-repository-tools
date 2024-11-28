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
}

void DebianRepositoryReleaseFileTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianRepositoryReleaseFile release_file;

    ISHIKO_TEST_PASS();
}
