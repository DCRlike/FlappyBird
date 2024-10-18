#include "include/Pipe.h"


void Pipe::Initialize()
{
    up_height=0;
    down_height=0;
    x=77;//初始就要在屏幕边缘
}


void Pipe::Set_height(int screenheight, int gapheight)
{

    up_height = rand() % (screenheight -1 - gapheight);
    down_height = screenheight - up_height - gapheight;
}

int Pipe::Get_upheight() const
{
    return up_height;
}

int Pipe::Get_downheight() const
{
    return down_height;
}

int Pipe::Get_x() const
{
    return x;
}

void Pipe::Move()
{
    x--;
}
bool Pipe::If_isoutscreen()
{
    if (x==1)
    {
        return true;
    }
    else return false;
}


