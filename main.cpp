#include "include/Game.h"
#include <conio.h>

int main()
{
    int score=0;
    Game Game;
    Game.Initialize();
    Game.Showmenu();
    while (true)
    {
        Set_ConsoleSize(80,25);
        char c=getch();
        if (c=='1')
        {
            Game.Start();

        }
        else if (c=='2')
        {
            break;
        }

    }

}