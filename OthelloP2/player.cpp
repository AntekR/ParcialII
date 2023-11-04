#include "player.h"
#include "board.h"


Player::Player(string nick, char colorCard)
{
    name = nick;
    color = colorCard;
    score = 0;
}

char Player::getColor(){
    return color;
}

string Player:: getName(){
    return name;
}


bool Player::checkAvailableMoves(Board boardMatrix, int rowSelection, int columnSelection, char colorPlayer){
    bool available = false;
    char opponent = (colorPlayer == '-') ? '+' : '-';

    // Valida que la posicion seleccionada por el usuario no este fuera del tablero
    if(0<rowSelection-1<boardMatrix.getRow() && 0<columnSelection-1<boardMatrix.getRow()){
        // Valida si hay encierro de manera vertical hacia arriba
        // Pendiente validar la comparacion a 0.
        if(rowSelection-1>0 && boardMatrix.getBoard()[rowSelection-2][columnSelection-1]==opponent){
            available = true;
        }
        // Valida si hay encierro de manera vertical hacia abajo
        if(rowSelection-1<boardMatrix.getRow() && boardMatrix.getBoard()[rowSelection+2][columnSelection-1]==opponent){
            available = true;
        }
        //Valida si hay encierro de manera horizontal hacia la derecha
        if(columnSelection-1>=0 && boardMatrix.getBoard()[rowSelection-1][columnSelection]==opponent){
            available = true;
        }
        //Valida si hay encierro de manera horizontal hacia la izquierda
        if(columnSelection-1<boardMatrix.getRow() && boardMatrix.getBoard()[rowSelection-1][columnSelection-2]==opponent){
            available = true;
        }
    }else{
        available = false;
    }

    return available;
}
