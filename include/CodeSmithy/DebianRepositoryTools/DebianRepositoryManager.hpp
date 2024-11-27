// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYMANAGER_HPP
#define GUARD_CODESMITHYIDE_DEBIANREPOSITORYTOOLS_DEBIANREPOSITORYMANAGER_HPP

#include <string>

namespace CodeSmithy
{
    class DebianRepositoryManager
    {
    public:
        DebianRepositoryManager();

        void generatePackagesFile(const std::string& binary_packages_tree_path);

    private:
        std::string m_dpkg_scanpackages_path;
    };
}

#endif
