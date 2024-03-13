#pragma once
#include <vector>
#include "Account.hpp"
#include "Persistence.hpp"
#include "./encryption/FirstEncrypter.hpp"

class GenerateManager //: public IGenerateManager
{
    public:

    GenerateManager();
    ~GenerateManager();
    std::vector<Account> GetPasswords(const char* input); //override;
    void PrintPassswords(const char* input, const char* userOrSite) const;

    private:
    
    Persistence* m_persistence;
    FirstEncrypter* m_encrypter;
};