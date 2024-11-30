// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianRepositoryReleaseFile.hpp"
#include <boost/filesystem.hpp>

using namespace CodeSmithy;

DebianRepositoryReleaseFile::DebianRepositoryReleaseFile(const Ishiko::UTCTime& date)
    : m_date(date)
{
}

void DebianRepositoryReleaseFile::setDate(const Ishiko::UTCTime& date)
{
    m_date = date;
}

void DebianRepositoryReleaseFile::addFile(const std::string& path)
{
    std::string generic_path = boost::filesystem::path(path).generic_string();
    size_t file_size = Ishiko::FileSystem::GetFileSize(generic_path.c_str());
    m_files.emplace_back(FileInfo{Ishiko::SHA256Hash(), file_size, generic_path});
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
