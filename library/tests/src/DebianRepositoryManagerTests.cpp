// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianRepositoryManagerTests.hpp"
#include "CodeSmithy/DebianRepositoryTools/DebianRepositoryManager.hpp"
#include <Ishiko/BasePlatform.hpp>

using namespace CodeSmithy;

DebianRepositoryManagerTests::DebianRepositoryManagerTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "DebianRepositoryManager tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("generatePackagesFile test 1", GeneratePackagesFileTest1);
}

void DebianRepositoryManagerTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianRepositoryManager repository_manager;

    ISHIKO_TEST_PASS();
}

void DebianRepositoryManagerTests::GeneratePackagesFileTest1(Ishiko::Test& test)
{
#if ISHIKO_OS == ISHIKO_OS_WINDOWS
    test.skip();
#endif

    const boost::filesystem::path binary_packages_tree_path = test.context().getDataDirectory();
    const boost::filesystem::path output_path =
        test.context().getOutputPath("DebianRepositoryManagerTests_GeneratePackagesFileTest1");

    DebianRepositoryManager repository_manager;
    repository_manager.generatePackagesFile(binary_packages_tree_path.string(), output_path.string());

    ISHIKO_TEST_PASS();
}
