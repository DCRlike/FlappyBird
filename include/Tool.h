//
// Created by dcrli on 24-10-13.
//

#ifndef TOOL_H
#define TOOL_H
#include <windows.h>
#include <conio.h>
#include "Bird.h"
#include "Pipe.h"

void Set_ConsoleSize(int width, int height);
void Set_CursorPosition(int x, int y);
void Draw_bird(const Bird& Bird);
void Erease_bird(const Bird& Bird);
void Draw_pipe(const Pipe& pipe);
void Erease_pipe(const Pipe& pipe);
void Draw_border();
void Draw_Score(int& score);
void Clear();
bool If_flap();


#endif //TOOL_H
