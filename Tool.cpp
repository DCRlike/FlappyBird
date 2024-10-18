
#include <iostream>
#include "include/Tool.h"

void Set_ConsoleSize(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Set_CursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}
void Draw_bird(const Bird& Bird)
{
    Set_CursorPosition(Bird.Get_x(),Bird.Get_y());
    std::cout<< "@";
}

void Erease_bird(const Bird& Bird)
{
    Set_CursorPosition(Bird.Get_x(),Bird.Get_y());
    std::cout<< " ";
}

void Draw_pipe(const Pipe& pipe)
{

    for (int i=1;i<pipe.Get_upheight();++i)
    {
        Set_CursorPosition(pipe.Get_x(),i);
        std::cout<<"***";
    }
    for (int i=0;i<pipe.Get_downheight();i++)
    {
        Set_CursorPosition(pipe.Get_x(),25-pipe.Get_downheight()+i);//25是屏幕高度
        std::cout<<"***";
    }
}

void Erease_pipe(const Pipe& pipe)
{
    for (int i=1;i<pipe.Get_upheight();++i)
    {
        Set_CursorPosition(pipe.Get_x(),i);
        std::cout<<"   ";
    }
    for (int i=0;i<pipe.Get_downheight();i++)
    {
        Set_CursorPosition(pipe.Get_x(),25-pipe.Get_downheight()+i);//25是屏幕高度
        std::cout<<"   ";
    }
}

void Draw_border() {
    
    
    for (int i = 0; i < 100; ++i) {
        Set_CursorPosition(i, 0);
        std::cout << "#";
        Set_CursorPosition(i, 25);
        std::cout << "#";
    }
    for (int i = 0; i < 25; ++i) {
        Set_CursorPosition(0, i);
        std::cout << "#";
        Set_CursorPosition(80, i);
        std::cout << "#";
        Set_CursorPosition(100, i);
        std::cout << "#";

    }
}
void Draw_Score(int& score)
{
    Set_CursorPosition(87,12);
    std::cout << "Score";
    Set_CursorPosition(87,13);
    std::cout << score;
}


bool If_flap() {
    return _kbhit() && _getch() ==' ';
}