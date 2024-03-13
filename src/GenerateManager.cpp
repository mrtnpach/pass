#include <string>
#include "GenerateManager.hpp"
#include "PrintTools.hpp"

GenerateManager::GenerateManager()
{
    m_encrypter = new FirstEncrypter();
    m_persistence = new Persistence();
}

GenerateManager::~GenerateManager()
{
    delete m_encrypter;
    delete m_persistence;
}

void GenerateManager::PrintPassswords(const char* input, const char* userOrSite) const
{
    std::vector<Account> all = m_persistence->GetAllAccounts();
    bool isSearch = (userOrSite != nullptr);
    bool noMatches = true;

    for(size_t i = 0; i < all.size(); i++)
    {
        Account account = all[i];
        std::string accountUser = account.getUsername();
        std::string accountSite = account.getSite();

        bool matchesSearch =    isSearch && (
                                accountUser.find(userOrSite, 0) != std::string::npos || 
                                accountSite.find(userOrSite, 0) != std::string::npos
                                );

        if(isSearch && !matchesSearch)
        {
            continue;
        }
        else if(!isSearch || matchesSearch)
        {
            noMatches = false;

            int userSeed = m_encrypter->GenerateSeed(accountUser.c_str());
            int siteSeed = m_encrypter->GenerateSeed(accountSite.c_str());

            std::string generatedPass = m_encrypter->GeneratePassword(input, userSeed, siteSeed, account.getPassLength());

            PrintAccountInfo(accountUser.c_str(), accountSite.c_str(), generatedPass.c_str());
        }
    }

    if(noMatches)
    {
        PrintMessage("No matches.");
    }
}