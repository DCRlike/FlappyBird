//
// Created by dcrli on 24-10-10.
//

// Bird.h
#ifndef BIRD_H
#define BIRD_H

class Bird {
public:
    void Initialize(int x, int y);
    void flap();
    void fall();
    int Get_x() const;
    int Get_y() const;
private:
    int x, y;
    int velocity;
};

#endif // BIRD_H