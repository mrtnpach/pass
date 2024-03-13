#include "Persistence.hpp"
#include <libloaderapi.h>
#include <iostream>

Persistence::Persistence()
{
    ReadAllAccounts();
}

Persistence::~Persistence()
{
    for(size_t i = 0; i < m_allAccounts.size(); i++)
    {
        Account* account = &m_allAccounts[i];
        delete account;
    }
}

size_t Persistence::GetAccountCount(std::ifstream& fileIn)
{
    size_t count = 0;

    if(fileIn.is_open())
    {
        fileIn.seekg(0);
        while(!fileIn.eof())
        { 
            std::string buffer; 
            std::getline(fileIn, buffer, '\n');
            count++;
        }
        fileIn.seekg(0);
    }
    return count;
}

void Persistence::ReadAllAccounts()
{
    std::ifstream fileIn(m_accountsFileName);
    if(fileIn.is_open())
    {
        size_t accountCount = GetAccountCount(fileIn);
        m_allAccounts.reserve(accountCount);

        while(!fileIn.eof())
        { 
            std::string user; 
            std::string site;
            std::string length;

            std::getline(fileIn, user, '@');
            std::getline(fileIn, site, '=');
            std::getline(fileIn, length, '\n');

            Account readAccount(user, site, std::stoi(length));
            m_allAccounts.emplace_back(readAccount);
            // Account* readAccount = new Account(user, site, std::stoi(length));
            // m_allAccounts.push_back(*readAccount); 
        }
        fileIn.close();
    }
}

//! '\n' adds a new line below, which causes an emppty read before reaching eof.
//TODO Try ('\n' + user + name) when adding new account to the list, if txt is empty, don't add '\n'.
//* Right now adding sites is done directly through the text file
// void Persistence::SaveAccount(Account account)
// {
//     std::ofstream fileOut(m_accountsFileName, std::ios::app);
//     if(fileOut.is_open())
//     {
//         int pos = (int)fileOut.tellp();
//         std::string newLine = pos == 0 ? "" : "\n";
//         std::string user = account.getUsername() + "@"; 
//         std::string site = account.getSite();

//         fileOut << (newLine + user + site);

//         fileOut.close();

//         m_allAccounts.push_back(account);
//     }
// }

Account Persistence::GetAccount(std::string userName, std::string siteName)
{
    for(size_t i = 0; i < m_allAccounts.size(); i++)
    {
        if(m_allAccounts[i].getSite() == siteName && m_allAccounts[i].getUsername() == userName)
        {
            return m_allAccounts[i];
        }
    }
    throw("Account doesn't exist.");
}

std::vector<Account> Persistence::GetAllAccounts()
{
    return m_allAccounts;
}