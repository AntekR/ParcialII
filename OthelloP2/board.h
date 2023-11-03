#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>

using namespace std;

class board
{
public:

    board(int row, int column);
    ~board();

    void placeCard(int row, int column, char color);
    bool checkValidPlay(int row, int column, char color);
    void showBoard();
    void saveGame(string file);
    void loadGame(string file);

protected:
    char** boardMatrix;
    int rowBoard;
};

#endif // BOARD_H
