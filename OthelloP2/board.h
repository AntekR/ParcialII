#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class board
{
public:
    // Crear un tablero segun el tamaño ingresado
    board(int row, int column);
    ~board();

    // Permite poner una ficha segun la posición
    void placeCard(int row, int column, char color);
    /* Valida que la jugada o la posición que el usuario desea poner haga algún tipo
     * de encierro sandwich para que pueda poner la ficha
    */
    bool checkValidPlay(int row, int column, char color);
    // Muestra el tablero del juego
    void showBoard();
    // Guarda los datos de la partida, nombres de jugadores y sus puntuaciones
    void saveGame();
    // Carga los datos anteriormente guardados.
    void loadGame();

protected:
    char** boardMatrix;
    int rowBoard;
};

#endif // BOARD_H
