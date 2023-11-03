#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
public:
    Player(string name, char color);
    ~Player();

    bool checkAvailableMoves(int row, int column, int color);
    void placeCard(int row, int column, int color);
    string getName();
    char getColor();

private:

    string name;
    char color;

protected:
    int score;
};

#endif // PLAYER_H
