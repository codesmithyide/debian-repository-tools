// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CommandLineSpecification.hpp"
#include <Ishiko/Errors.hpp>
#include <Ishiko/Terminal.hpp>
#include <exception>
#include <sstream>

int main(int argc, char* argv[])
{
    try
    {
        Ishiko::Error error;
        error.extensions().install<Ishiko::InfoErrorExtension>();

        return error.code().value();
    }
    catch (const std::exception& e)
    {
        std::stringstream message;
        message << "EXCEPTION: " << e.what() << std::endl;
        Ishiko::TerminalOutput(stderr).write(message.str(), Ishiko::ColorName::red);

        // TODO
        return -1;
    }
    catch (...)
    {
        // TODO
        return -1;
    }
}
