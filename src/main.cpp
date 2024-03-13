//#include <string>
#include <string.h>
#include "GenerateManager.hpp"
#include "PrintTools.hpp"

int main(int argc, char* argv[])
{
    PrintBanner("PASSWORDS", '#', 95);

    GenerateManager* manager = new GenerateManager();

    if(argc < 2 || argc > 3)
    {
        PrintMessage("Full command should look like this:\n\n\t\t \\pass [password] [user or site]");
    }
    else
    {
        manager->PrintPassswords(argv[1], argv[2]);
    }
    
    PrintDivider('#', 95, COLOR_DARK_RED);
}