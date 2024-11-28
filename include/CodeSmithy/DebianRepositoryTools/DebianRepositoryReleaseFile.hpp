// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYRELEASEFILE_HPP
#define GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYRELEASEFILE_HPP

#include <Ishiko/FileSystem.hpp>

namespace CodeSmithy
{
    class DebianRepositoryReleaseFile
    {
    public:
        void write(Ishiko::TextFile& file);
    };
}

#endif
