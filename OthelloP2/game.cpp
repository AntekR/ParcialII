#include "game.h"
#include "player.h"


Game::Game(int row, string nick1, char color1, string nick2, char color2)
{
    //Inicializa el tablero
    boardMatrix = new Board(row,row);

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

    //Crea un bucle que funcionaria hasta que el estado cambia de EN_JUEGO es decir pase a FINALIZADO
    while(status != Status::FINALIZADO){

        //Se llama al metodo makeMove para que el jugador actual haga su movimiento
        makeMove();


        //Y con este metodo se valida si el juego ya finalizo.
        checkEnd();
    }
}

void Game::makeMove(){

    //Se muestra el tablero actual
    boardMatrix->showBoard();

    //Solicitar al usuario posicion de su jugada
    int rowSelection, columnSelection;
    cout << "Turno de " << turn->getName() << ".";
    cout << "Ingrese la fila: "; cin >> rowSelection;
    cout << "Ingrese la columna: "; cin >> columnSelection;

    //Validar
    if(!Player::checkAvailableMoves(boardMatrix,rowSelection,columnSelection,turn->getColor()){

        cout << "Movimiento no valido" << endl;
        // Este return permite que el codigo siguiente no se ejecute, es decir para el metodo en este punto
        return;
    }



    //Board::checkValidPlay()

}

void Game::checkEnd(){

}
