// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include <Ishiko/BasePlatform.hpp>
#include <Ishiko/TestFramework.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification command_line_spec;
        Configuration configuration = command_line_spec.createDefaultConfiguration();
#if ISHIKO_OS == ISHIKO_OS_LINUX
        configuration.set("context.application-path", "../../../../bin/CodeSmithyDebianRepositoryToolsCLI");
#elif ISHIKO_OS == ISHIKO_OS_WINDOWS
        configuration.set("context.application-path", "../../../../bin/x64/CodeSmithyDebianRepositoryToolsCLI.exe");
#else
#error Unsupported or unrecognized OS
#endif
        CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        TestHarness the_test_harness("CodeSmithy Debian Repository Tools CLI Tests", configuration);

        TestSequence& the_tests = the_test_harness.tests();

        return the_test_harness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
