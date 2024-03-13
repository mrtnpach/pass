#include "FirstEncrypter.hpp"

FirstEncrypter::FirstEncrypter()
{
    _digitBankColumnCount = sizeof(digitsBank[0]) / sizeof(char);
    _digitBankRowCount = sizeof(digitsBank) / sizeof(digitsBank[0]);
};

FirstEncrypter::~FirstEncrypter(){};

int FirstEncrypter::GenerateRandomNumber()
{
    std::random_device generator;
    std::mt19937 twister(generator());
    std::uniform_int_distribution<int> distribution(1000, 9999);

    return distribution(generator);
}

size_t FirstEncrypter::CalculateStringLength(const char* string)
{
    size_t characterCount = 0;
    size_t index = 0;

    while(string[index])
    {
        characterCount++;
        index++;
    }

    return characterCount;
}

int FirstEncrypter::GenerateSeed(const char* name)
{
    int seed = 0;
    int customSeed = _customSeed; // generateRandomNumber();

    int firstValue = (int)name[0];
    int nameLength = CalculateStringLength(name);
    int salt = nameLength + (int)name[nameLength] + customSeed % 350;

    for (int i = 0; i < nameLength; i++)
    {
        int asciiValue = (int)name[i];
        seed += asciiValue + salt * (i + 2) + customSeed * firstValue + nameLength * salt;
    }

    seed = seed % 100000;

    return seed;
}

std::string FirstEncrypter::GeneratePassword(const char* inputString, const int userSeed, const int siteSeed, const size_t length)
{
    if(length <= 0 || length > 50)
    {
        return "INVALID PASSWORD LENGHT";
    }

    std::string generatedPassword = "";
    int salt = (userSeed + siteSeed + _saltConstant * length) % 100;
    int inputLength = CalculateStringLength(inputString);

    for (int i = 0; i < length; i++)
    {
        int currentAscii = (int)inputString[i % inputLength];
        int row = (currentAscii + userSeed + i * _rowSelectionSalt + salt + siteSeed + length) % _digitBankRowCount;
        int digit = (currentAscii + userSeed + i * _columnSelectionSalt + salt + siteSeed + length) % _digitBankColumnCount;

        char obtained = digitsBank[row][digit];
        obtained = (obtained == 0) ? '?' : obtained;

        generatedPassword += obtained;
    }

    return generatedPassword;
}