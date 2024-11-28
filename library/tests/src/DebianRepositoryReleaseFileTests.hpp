// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_TESTS_DEBIANREPOSITORYRELEASEFILETESTS_HPP
#define GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_TESTS_DEBIANREPOSITORYRELEASEFILETESTS_HPP

#include <Ishiko/TestFramework.hpp>

class DebianRepositoryReleaseFileTests : public Ishiko::TestSequence
{
public:
    DebianRepositoryReleaseFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
