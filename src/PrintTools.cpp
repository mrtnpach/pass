#include <iostream>
#include <string.h>
#include <Windows.h>
#include "PrintTools.hpp"

void PrintDivider(const char symbol, const size_t length, const size_t color)
{
    SetFontColor(color);
    for(size_t i = 0; i < length; i++)
    {
        std::cout << symbol;
    }
    std::cout << std::endl;
    SetFontColor(COLOR_WHITE);
}

// ! Does not work most of the time
// const char* FillText(const char* phrase, const char filler, size_t width)
// {
//     size_t phraseLength = strlen(phrase);
//     size_t phraseMiddle = phraseLength / 2;

//     width = (phraseMiddle % 2 == 0) ? width + 1 : width;

//     size_t leftFillLength = ((width / 2) - phraseMiddle);

//     char* filledText = new char[width];
//     size_t filledTextOffset = 0;

//     for(filledTextOffset; filledTextOffset < leftFillLength; filledTextOffset++)
//     {
//         filledText[filledTextOffset] = filler;
//     }
//     strncat(filledText, phrase, phraseLength);
//     filledTextOffset += phraseLength;
//     for(filledTextOffset; filledTextOffset < width - 1; filledTextOffset++)
//     {
//         filledText[filledTextOffset] = filler;
//     }
//     strncat(filledText, "\0", 1);

//     return filledText;
// }

void PrintBanner(const char* title, const char dividerSymbol, size_t dividerLength)
{
    std::cout << std::endl;
    PrintDivider(dividerSymbol, dividerLength,  COLOR_DARK_RED);
    // const char* bannerCenter = FillText(title, '-', dividerLength);
    std::cout << "\t\t\t\t\tPASSWORDS" << std::endl;
    PrintDivider(dividerSymbol, dividerLength, COLOR_DARK_RED);
    std::cout << std::endl;
    // delete[] bannerCenter;
}

void PrintMessage(const char* message)
{
    std::cout << "\t" << message << std::endl;
    std::cout << std::endl;
}

void SetFontColor(const size_t color)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);   
}

void PrintAccountInfo(const char* user, const char* site, const char* pass)
{
    SetFontColor(COLOR_WHITE);
    std::cout << "\t" << user;
    SetFontColor(COLOR_GRAY);
    std::cout << " @ "; 
    SetFontColor(COLOR_WHITE);
    std::cout << site; 
    SetFontColor(COLOR_GRAY);
    std::cout << " : ";
    SetFontColor(COLOR_WHITE);
    std::cout << pass << std::endl;
    std::cout << std::endl;
    SetFontColor(COLOR_WHITE);
}