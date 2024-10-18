//
// Created by dcrli on 24-10-12.
//

#ifndef PIPE_H
#define PIPE_H

#include <ctime>
#include <cstdlib>

class Pipe
{
public:
    void Initialize();
    void Set_x(int new_X);
    int Get_upheight() const;
    int Get_downheight() const;
    int Get_x() const;
    void Set_height(int screenheight,int gapheight);
    void Move();
    bool If_isoutscreen();
    


private:
    int up_height;
    int down_height;
    int x;
};

#endif //PIPE_H
