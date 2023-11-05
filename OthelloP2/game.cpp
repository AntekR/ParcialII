#include "game.h"
#include "player.h"


Game::Game(int row, string nick1, char color1, string nick2, char color2)
{

    //Inicializa el tablero
    board = new Board(row);

    //Crea los jugadores
    player1 = new Player(nick1, color1);
    player2 = new Player(nick2, color2);

    //Se inicializa el turno con el jugador 1
    turn = player1;

    //Establece el juego en modo inicio
    status = Status::INICIAR;
}

Game::~Game(){
}

void Game::startGame(){
    //Se establece el estado del juego en proceso (en medio de este)
    status = Status::EN_JUEGO;

    turn = player1;

    board->showBoard();
}

void Game::makeMove(){


    //Solicitar al usuario posicion de su jugada
    int rowSelection, columnSelection;
    cout << "Turno de " << turn->getName() << "." << endl;
    cout << "Ingrese la fila: "; cin >> rowSelection;
    cout << "Ingrese la columna: "; cin >> columnSelection;

    /*Validar si tiene movimientos disponibles, es decir alguna posicion que le permita hacer un
     * encierro, si no tiene ninguna el movimiento seria invalido
    */
    if(board->checkValidPlay(rowSelection,columnSelection,turn->getColor())==false){

        cout << "Movimiento no valido, no hay encierros" << endl;
        turn = (turn == player1) ? player2 : player1;
        // Este return permite que el codigo siguiente no se ejecute, es decir para el metodo en este punto
        return;
    }
    // Valida los encierros, hace los cambios y pone la ficha en el lugar seleccionado
    board->placeCard(rowSelection,columnSelection,turn->getColor());
    //board->checkValidPlay(rowSelection-1,columnSelection-1,turn->getColor());
    board->showBoard();


    // Cambio de turno
    turn = (turn == player1) ? player2 : player1;

}

Status Game::checkEnd(){

    /* Se valida si el jugador o jugadores tienen movimientos disponibles
    */
    if(board->checkAvailableMoves(turn->getColor())==false){
        turn =  (turn == player1) ? player2 : player1;
        if(board->checkAvailableMoves(turn->getColor())==false){

            return Status::FINALIZADO;
        }else{
            return Status::EN_JUEGO;
        }
    }else{
        return Status::EN_JUEGO;
    }
}
