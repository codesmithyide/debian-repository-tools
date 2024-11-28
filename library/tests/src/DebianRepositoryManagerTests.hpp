// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_TESTS_DEBIANREPOSITORYMANAGERTESTS_HPP
#define GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_TESTS_DEBIANREPOSITORYMANAGERTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class DebianRepositoryManagerTests : public Ishiko::TestSequence
{
public:
    DebianRepositoryManagerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void GeneratePackagesFileTest1(Ishiko::Test& test);
};

#endif
