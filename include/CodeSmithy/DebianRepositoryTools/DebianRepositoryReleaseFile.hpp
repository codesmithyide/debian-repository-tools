// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYRELEASEFILE_HPP
#define GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYRELEASEFILE_HPP

#include <Ishiko/Crypto.hpp>
#include <Ishiko/FileSystem.hpp>
#include <Ishiko/Time.hpp>
#include <string>
#include <vector>

namespace CodeSmithy
{
    class DebianRepositoryReleaseFile
    {
    public:
        DebianRepositoryReleaseFile(Ishiko::UTCTime& date);

        void setDate(Ishiko::UTCTime& date);
        void addFile(const std::string& path);

        void write(Ishiko::TextFile& file);

    private:
        struct FileInfo
        {
            Ishiko::SHA256Hash hash;
            size_t file_size;
            std::string path;
        };

        Ishiko::UTCTime& m_date;
        std::vector<FileInfo> m_files;
    };
}

#endif
