#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Board
{
public:
    // Crear un tablero segun el tamaño ingresado
    Board(int row);
    ~Board();

    // Permite poner una ficha segun la posición
    void placeCard(int row, int column, char color);
    /* Valida que la jugada o la posición que el usuario desea poner haga algún tipo
     * de encierro sandwich para que pueda poner la ficha
    */
    bool checkValidPlay(int row, int column, char color);

    /*Valida si tiene movimientos disponibles*/
    int checkAvailableMoves(char colorPlayer);

    //Valida si el tablero esta lleno
    bool checkFullBoard();

    //Obtener puntuacion

    // Muestra el tablero del juego
    void showBoard();
    // Guarda los datos de la partida, nombres de jugadores y sus puntuaciones
    void saveGame();
    // Carga los datos anteriormente guardados.
    void loadGame();

    int getRow();
    char** getBoard();

protected:
    char** boardMatrix;
    int rowBoard;
};

#endif // BOARD_H
