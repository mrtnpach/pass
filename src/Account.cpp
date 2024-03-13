#include "Account.hpp"

Account::Account(std::string username, std::string sitename, size_t passLength)
    : m_username(username), m_site(sitename), m_passLength(passLength)
{

}

Account::~Account(){}

std::string Account::getUsername()
{
    return m_username;
}

std::string Account::getSite()
{
    return m_site;
}

size_t Account::getPassLength()
{
    return m_passLength;
}