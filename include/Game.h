
#ifndef GAME_H
#define GAME_H
#include "Bird.h"
#include "Pipe.h"
#include "Tool.h"
#include <vector>

class Game
{
public:
    void Initialize();
    void Start();
    void End();
    void Showmenu();
    int If_hit();
    void Generate_pipe(int x);
    void Plus_score(int& score);

private:
    Bird Bird;
    std::vector <Pipe> Pipes;
    


};

#endif //GAME_H
