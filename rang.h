#include <stdio.h>
#include <windows.h>
typedef enum
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8,
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12,
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}
/*int main()
{
    setTextColor(LIGHT_BLUE);
    printf("Hello ");
    setTextColor(LIGHT_GREEN);
    printf("World!\n");
    setTextColor(LIGHT_YELLOW);
    printf("Source");
    setTextColor(LIGHT_PURPLE);
    printf("Sara");
    setTextColor(LIGHT_AQUA);
    printf(".");
    setTextColor(LIGHT_RED);
    printf("Com");
    setTextColor(WHITE);
    return 0;
}*/
