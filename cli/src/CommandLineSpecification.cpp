// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CommandLineSpecification.hpp"

using namespace CodeSmithy;

CommandLineSpecification::CommandLineSpecification()
{
    addPositionalOption(1, "command", {Ishiko::CommandLineSpecification::OptionType::single_value});

    Ishiko::CommandLineSpecification::CommandDetails& create_command_details = addCommand("command", "create");
}
