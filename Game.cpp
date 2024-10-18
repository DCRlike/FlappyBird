#include "include/Game.h"
#include <iostream>
#include <thread>


int num1 = 0;
int score = 0;
void Game::Initialize()
{
    Bird.Initialize(20, 10);
    Generate_pipe(1);
}
void Game::Generate_pipe(int x)
{
    for (int i = 0; i < x; ++i)
    {
        Pipe Pipe;
        Pipe.Initialize();
        Pipe.Set_height(25, 8); // 我默认25是屏幕高度，5是管道间差距
        Pipes.push_back(Pipe);
    }
}

void Game::Plus_score(int &score)
{
    score++;
}
int Game::If_hit()
{
    // 检测小鸟是否碰到边框
    if (Bird.Get_y() <= 0 || Bird.Get_y() >= 24)
    {
        return 1;
    }

    // 检测小鸟是否碰到管道
    const Pipe &it = *Pipes.begin();
    if ((Bird.Get_x() == it.Get_x() || Bird.Get_x() == it.Get_x() + 1 || Bird.Get_x() == it.Get_x() + 2) &&
        (Bird.Get_y() < it.Get_upheight() || Bird.Get_y() > 25 - it.Get_downheight()))
    {
        return 1;
    }
    if (Bird.Get_x()==it.Get_x())
    {
        return 2;
    }
    return 0;
}
void Game::End()
{
    system("cls");
    Set_CursorPosition(32,12);
    std::cout << "Game Over!";
    Set_CursorPosition(33,13);
    std::cout << "Your Score is: " << score << std::endl;

    std::cin.get();
}
void Game::Showmenu()
{
    std::cout << "====================\n";
    std::cout << "  Flappy Bird Game\n";
    std::cout << "====================\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Quit Game\n";
    std::cout << "Please Select: ";
}
void Game::Start()
{
    srand((unsigned)time(NULL));
    system("cls");
    Draw_border();

    while (true)
    {

        if (!Pipes.empty() && Pipes.front().If_isoutscreen())
        {
            Pipes.erase(Pipes.begin());
        }

        // 绘制管道
        for (auto &pipe : Pipes)
        {
            pipe.Move();
            Draw_pipe(pipe);
        }
        num1++;
        if (num1 == 13)
        {
            Generate_pipe(1);
            num1 = 0;
        }

        if (If_flap())
        {
            Bird.flap();
        }
        Bird.fall();
        Draw_bird(Bird);

        if (If_hit() == 1)
        {
            End();
            break;
        }
        else if (If_hit() == 2)
        {
            Plus_score(score);
        }
        Draw_Score(score);
        _sleep(100);

        Erease_bird(Bird);
        for (auto &pipe : Pipes)
        {
            Erease_pipe(pipe);
        }

        // std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 每秒10帧
    }
}
