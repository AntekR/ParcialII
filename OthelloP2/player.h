#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "board.h"

using namespace std;

class Player
{
public:

    Player(string name, char color);
    ~Player();

    bool checkAvailableMoves(Board* boardMatrix,int rowSelection, int columnSelection, char colorPlayer);
    string getName();
    char getColor();
    void setScore(int scoreAct);
    int getScore();

private:

    string name;
    char color;

protected:
    int score;
};

#endif // PLAYER_H
