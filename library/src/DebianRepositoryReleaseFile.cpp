// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianRepositoryReleaseFile.hpp"

using namespace CodeSmithy;

DebianRepositoryReleaseFile::DebianRepositoryReleaseFile(Ishiko::UTCTime& date)
    : m_date(date)
{
}

void DebianRepositoryReleaseFile::setDate(Ishiko::UTCTime& date)
{
    m_date = date;
}

void DebianRepositoryReleaseFile::addFile(const std::string& path)
{
    size_t file_size = Ishiko::FileSystem::GetFileSize(path.c_str());
    m_files.emplace_back(FileInfo{Ishiko::SHA256Hash(), file_size, path});
    m_files.back().hash.updateFromFile(path);
}

void DebianRepositoryReleaseFile::write(Ishiko::TextFile& file)
{
    file.writeLine("Date: " + m_date.toRFC7231String());
    if (!m_files.empty())
    {
        file.writeLine("SHA256:");
        for (const FileInfo& info : m_files)
        {
            // TODO: the path needs to be relative to the release file path
            file.writeLine(" " + info.hash.value().toHexString() + " " + std::to_string(info.file_size) + " "
                + info.path);
        }
    }
}
