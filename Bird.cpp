#include "include/Bird.h"
void Bird::Initialize(int x1, int y1)
{
    x=x1;
    y=y1;
    velocity=0;
} 

void Bird::flap()
{
    velocity = -2;
}
void Bird::fall()
{
    y += velocity, velocity += 1;
}
int Bird::Get_x() const
{
    return x;
}
int Bird::Get_y() const
{
    return y;
}