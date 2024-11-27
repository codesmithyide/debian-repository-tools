// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianRepositoryManager.hpp"
#include <Ishiko/Process.hpp>

using namespace CodeSmithy;

namespace
{
    Ishiko::CommandLine CreateGeneratePackagesFileCommandLine(const std::string& dpkg_scanpackages_path)
    {
        Ishiko::CommandLine command_line(dpkg_scanpackages_path);
        return command_line;
    }
}

DebianRepositoryManager::DebianRepositoryManager()
    : m_dpkg_scanpackages_path("/usr/bin/dpkg-scanpackages")
{
}

void DebianRepositoryManager::generatePackagesFile()
{
    Ishiko::CommandLine command_line = CreateGeneratePackagesFileCommandLine(m_dpkg_scanpackages_path);
    Ishiko::ChildProcessBuilder process_builder(command_line, Ishiko::CurrentEnvironment());
    Ishiko::ChildProcess process = process_builder.start();
    process.waitForExit();
    int exit_code = process.exitCode();
    if (exit_code != 0)
    {
        // TODO
        throw 0;
        /*
        Throw(BuildToolchainErrorCategory::Value::build_error, "Process launched by "
            + command_line.toString(Ishiko::CommandLine::Mode::quote_if_needed) + " exited with code "
            + std::to_string(exit_code), __FILE__, __LINE__);
            */
    }
}
