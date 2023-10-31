#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include <string>

using namespace std;


class Game
{
public:

    Game();
    void startGame();
    void makeMove();
    void checkEnd();
    void showBoard();
    void saveGame(string file);
    void loadGame(string file);

private:
    Board* board;
    Player player1;
    Player player2;
    Player turn;
};

#endif // GAME_H
