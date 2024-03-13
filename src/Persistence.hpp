#pragma once
#include <fstream>
#include <string>
#include <vector>
//#include <random>
#include "Account.hpp"

#define ASD true;

class Persistence
{
    public: 

    Persistence();
    ~Persistence();

    void SaveAccount(Account account);
    Account GetAccount(std::string userName, std::string siteName);
    std::vector<Account> GetAllAccounts();
    void ReadBank();

    private:
    
    void ReadAllAccounts();
    size_t GetAccountCount(std::ifstream& fileIn);

    // Todo: find a way to get the exe's directory
    std::string m_accountsFileName = "./accounts.txt";
    std::vector<Account> m_allAccounts;
};