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
    int rowSelection, columnSelection;

    do {
        //Solicitar al usuario posicion de su jugada
        cout << "\t\tTurno de " << turn->getName() << "." << endl;
        cout << "\t\tIngrese la fila: "; cin >> rowSelection;
        cout << "\t\tIngrese la columna: "; cin >> columnSelection;

        /*Validar si tiene movimientos disponibles, es decir alguna posicion que le permita hacer un
        * encierro, si no tiene ninguna el movimiento seria invalido
        */
        if(board->checkAvailableMoves(turn->getColor())==0){

            cout << "\t\tMovimiento no valido, no hay encierros" << endl;
            turn = (turn == player1) ? player2 : player1;
            // Este return permite que el codigo siguiente no se ejecute, es decir para el metodo en este punto
            return;
        }
    } while (board->checkValidPlay(rowSelection-1,columnSelection-1,turn->getColor())==false);


    // Valida los encierros, hace los cambios y pone la ficha en el lugar seleccionado
    board->placeCard(rowSelection-1,columnSelection-1,turn->getColor());
    calculateScore();
    cout << endl << "\t\tPuntaje de Jugadores" << endl;
    cout <<"\t\t"<<player1->getName() <<" " <<player1->getScore()<< "\t  " <<player2->getName() <<" " <<player2->getScore() << endl;
    board->showBoard();


    // Cambio de turno
    turn = (turn == player1) ? player2 : player1;

}

Status Game::checkEnd(){

    /* Se valida si el jugador o jugadores tienen movimientos disponibles
    */
    if(board->checkAvailableMoves(turn->getColor())==0){
        turn =  (turn == player1) ? player2 : player1;
        if(board->checkAvailableMoves(turn->getColor())==0){

            return Status::FINALIZADO;
        }else{
            return Status::EN_JUEGO;
        }
    }else if(board->checkFullBoard()==true){
        cout << "\t\tTablero lleno" << endl;
        return Status::FINALIZADO;
    }else{
        return Status::EN_JUEGO;
    }
}

void Game::calculateScore(){

    int negro=0; int blanco=0;
    for (int i = 0; i < board->getRow(); ++i) {
        for (int j = 0; j < board->getRow(); ++j) {
            if(board->getBoard()[i][j]=='*'){
                negro++;
            }else if(board->getBoard()[i][j]=='-'){
                blanco++;
            }
        }
    }
    if(player1->getColor()=='*'){
        player1->setScore(negro);
    }else player1->setScore(blanco);

    if(player2->getColor()=='*'){
        player2->setScore(negro);
    }else player2->setScore(blanco);
}

void Game::saveGame(){
    ofstream partidas("partidas.txt",ios::app);
    if(!partidas.is_open()){
        cerr << "\t\tNo se pudo abrir el archivo" << endl;
    }

    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    string tiempo = ctime(&time);
    int scoreW = ((player1->getScore() > player2->getScore()) ? player1->getScore() : player2->getScore());
    partidas << "Fecha y hora: " + tiempo + "\n";
    partidas << "Jugador 1: "+player1->getName() + "\n";
    partidas << "Jugador 2: "+player2->getName() + "\n";
    partidas << "Ganador: " + ((scoreW==player1->getScore()) ? player1->getName() : player2->getName())+"\n";
    partidas << "Puntaje ganador: " + to_string(scoreW) + "\n";
}

void Game::printResults(){
    cout << "\t\tJugador 1 (" <<player1->getName()<<") finalizo con un puntaje de: "<< player1->getScore()<< " fichas en total."<<endl;
    cout << "\t\tJugador 2 (" <<player2->getName()<<") finalizo con un puntaje de: "<< player2->getScore()<< " fichas en total."<<endl;
    int scoreW = ((player1->getScore() > player2->getScore()) ? player1->getScore() : player2->getScore());
    cout << "\t\tGanador: " << ((scoreW==player1->getScore()) ? player1->getName() : player2->getName()) << endl;
    cout << "\t\tPuntaje ganador: "<<to_string(scoreW)<<endl;
}

void Game::loadGame(){
    ifstream partidas("partidas.txt");

    if(!partidas.is_open()){
        cerr << "\t\tNo se puedo abrir el archivo" << endl;
        return;
    }
    string line;
    while(getline(partidas,line)){
        cout << "\t\t" << line << endl;
    }
}
