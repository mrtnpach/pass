#pragma once 
#include <string>

class Account
{
    public:
    
    Account() = default;
    Account(std::string username, std::string sitename, size_t passLength);
    ~Account();

    std::string getUsername();
    std::string getSite();
    size_t getPassLength();

    private: 

    std::string m_username;
    std::string m_site;
    size_t m_passLength;
    // char _username[USER_LENGTH];
    // char _site[SITE_LENGTH];
};