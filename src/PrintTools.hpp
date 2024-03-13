// ! Make PrintTools a singleton with handler as member attribute or a view class
// * Apparently the handler is just a copy of the value on the process table, closing it is not 
// * necessary and getting it causes almost no overhead
// https://docs.microsoft.com/en-us/windows/console/getstdhandle

void PrintDivider(const char symbol, const size_t length, const size_t color);
void PrintBanner(const char* title, const char dividerSymbol, size_t dividerLength);
void PrintMessage(const char* message);
void SetFontColor(const size_t color);
void PrintAccountInfo(const char* user, const char* site, const char* pass);

/* 
FOREGROUND_BLUE;  //1
FOREGROUND_GREEN; //2
FOREGROUND_RED;   //4
FOREGROUND_INTENSITY; //8 
*/
enum ConsoleColors
{
    COLOR_WHITE = 15, COLOR_BRIGHT_RED = 12, COLOR_BRIGHT_BLUE = 9, COLOR_BRIGHT_YELLOW = 13, COLOR_GRAY = 8,
    COLOR_DARK_RED = 4
};