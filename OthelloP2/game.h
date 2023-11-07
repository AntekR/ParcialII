#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

enum class Status;

class Game
{
public:
    Game(int row, string nick1, char color1, string nick2, char color2);
    ~Game();

    void startGame();
    void makeMove();
    Status checkEnd();
    void calculateScore();
    void saveGame();
    void printResults();
    void loadGame();

private:
    Board *board;
    Player *player1;
    Player *player2;
    Player *turn;

protected:
    Status status;

};

enum class Status{
    INICIAR, EN_JUEGO, FINALIZADO
};

#endif // GAME_H
