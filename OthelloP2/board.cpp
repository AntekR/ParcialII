#include "board.h"

Board::Board(int row)
{
    rowBoard = row;
    boardMatrix = new char*[row];
    for(int i=0; i<row; i++){
        boardMatrix[i] = new char[row];
    }

    //Rellenado de tablero y puesta de fichas centrales
    int fi=(row/2)-1; int col=(row/2)-1; char co='*';
    for (int f = 0; f < row; ++f) {
        for (int c = 0; c < row; ++c) {
            if(f==fi&&c==col&&co=='*'){
                boardMatrix[f][c]='*';
                col++;
                boardMatrix[f][++c]='-';
                fi ++; co='-';
            }else if(f==fi&&c==col&&co!='*'){
                boardMatrix[f][--c]='-';
                boardMatrix[f][++c]='*';
            }else{
                boardMatrix[f][c]='.';
            }
        }
    }
}

Board::~Board(){
    for (int i = 0; i < rowBoard; ++i) {
        delete[] boardMatrix[i];
    }
}

void Board::placeCard(int rowSelection, int columnSelection, char colorPlayer ){

    char opponent = (colorPlayer == '-') ? '*' : '-';
    // Validar si la posicion seleccionada esta dentro del tablero
    if(rowSelection>=0 && rowSelection<=rowBoard-1 && columnSelection>=0 && columnSelection<rowBoard && boardMatrix[rowSelection][columnSelection]=='.'){
        //                      Se valida encierros

        /*                            Vertical hacia arriba
         * En este condicional se valida que la posicion no este en la parte superior del tablero
         * y a la vez se valida si la ficha arriba de esa posicion es del oponente, si es asi
         * entonces ingresa a un for para buscar una ficha del jugador actual
         *
         *            Busca la posicion arriba que indico el usuario si la ficha es del oponente
        */
        if(rowSelection>=0 && boardMatrix[rowSelection-1][columnSelection]==opponent){
            /*Inicia un for para recorrer desde la ficha del oponente hacia arriba para buscar otra ficha de
            si mismo*/
            for (int i = rowSelection-1; i >= 0; i--) {
                /* En este condicional se verifica si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    /* Si el condicional anterior se cumple entonces ingresa a un for que permite
                     * recorrer la fila desde la posicion de esa otra ficha del jugador que hace
                     * el encierro hacia abajo para cambiar las fichas del oponente.
                    */
                    for (int j = rowSelection; j>i; j--) {
                        boardMatrix[j][columnSelection]=colorPlayer;
                    }
                    break;
                }
            }
        }
        /*                            Vertical hacia abajo
         * Se hace el proceso contrario del condicional anterior, manera de restar sumamos y aqui
         * usamos el total de filas que hay en el tablero para poder hacer la validacion y verificar que
         * no sea la ultima fila del tablero
         */
        if(rowSelection>=0 && rowSelection<rowBoard-1 && boardMatrix[rowSelection+1][columnSelection]==opponent){
            for (int i = rowSelection; i <rowBoard-1; i++) {
                /* En este condicional se busca si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    /* Si el condicional anterior se cumple entonces ingresa a un for que permite
                     * recorrer la fila desde la posicion de esa otra ficha del jugador que hace
                     * el encierro hacia arriba para cambiar las fichas del oponente.
                    */
                    for (int j = rowSelection; j<i; j++) {
                        boardMatrix[j][columnSelection]=colorPlayer;
                    }
                    break;
                }
            }
        }
        /*                            Horizontal hacia la derecha
         * En este condicional se valida que no este en la primera columna del tablero
        */
        if(columnSelection>=0 && columnSelection<rowBoard-1 && boardMatrix[rowSelection][columnSelection+1]==opponent){
            for (int j = columnSelection; j <= rowBoard-1; j++) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    for (int i = columnSelection; i<j ; i++) {
                        boardMatrix[rowSelection][i]=colorPlayer;
                    }
                    break;
                }
            }
        }

        /*                            Horizontal hacia la izquierda
         * En este condicional se valida que no este en la ultima columna del tablero
        */
        if(columnSelection>=0 && columnSelection<=rowBoard-1 && boardMatrix[rowSelection][columnSelection-1]==opponent){
            for (int j = columnSelection; j >=0 ; j--) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    for (int i = columnSelection; i>j ; i--) {
                        boardMatrix[rowSelection][i]=colorPlayer;
                    }
                    break;
                }
            }
        }


        /*                            Diagonal hacia la parte superior izquierda
         * En este condicional se valida que no este en la esquina superior izquierda del tablero
        */
        if(rowSelection>0 && columnSelection>0 && boardMatrix[rowSelection-1][columnSelection-1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection-1;

            while (i>=0 && j>=0 && j<=rowBoard-1) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection, y = columnSelection; x>i && y>j; x--,y--) {
                        boardMatrix[x][y]=colorPlayer;
                    }
                    break;
                }
                i--;
                j--;
            }
        }

        /*                            Diagonal hacia la parte superior derecha
         * En este condicional se valida que no este en la esquina superior derecha del tablero
        */
        if(rowSelection<=rowBoard-1 && columnSelection<rowBoard-1 && boardMatrix[rowSelection-1][columnSelection+1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection+1;

            while (i>=0 && j<rowBoard-1) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection, y = columnSelection; x>i && y<=j; x--,y++) {
                        boardMatrix[x][y]=colorPlayer;
                    }
                    break;
                }
                i--;
                j++;
            }
        }

        /*                            Diagonal hacia la parte inferior izquierda
         * En este condicional se valida que no este en la esquina inferior izquierda del tablero
        */

        if(rowSelection<rowBoard-1 && columnSelection<=rowBoard-1 && boardMatrix[rowSelection+1][columnSelection-1]==opponent){
            int i= rowSelection+1; //4+1=5
            int j= columnSelection-1; //6-1=5

            while (i<rowBoard && j<=rowBoard-1) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection, y = columnSelection; x<i && y>j; x++,y--) {
                        boardMatrix[x][y]=colorPlayer;
                    }
                    break;
                }
                i++;
                j--;
            }
        }



        /*                            Diagonal hacia la parte inferior derecha
         * En este condicional se valida que no este en la esquina inferior derecha del tablero
        */
        if(rowSelection<rowBoard-1 && columnSelection<rowBoard-1 && boardMatrix[rowSelection+1][columnSelection+1]==opponent){
            int i= rowSelection+1;
            int j= columnSelection+1;

            while (i<rowBoard-1 && j<rowBoard-1 && boardMatrix[i][j]==opponent) {
                i++;
                j++;
            }
            if(boardMatrix[i][j]==colorPlayer){
                for (int x = rowSelection, y = columnSelection; x<i && y<j; x++,y++) {
                    boardMatrix[x][y]=colorPlayer;
                }
            }
        }
    }else{
        cout << "Posicion llena, movimiento invalido" << endl;
    }

}

void Board::showBoard(){
    cout<<"\t\t   ";
    for(int k=0; k<rowBoard ; k++)
        cout<<k+1 << " ";
    cout << endl;
    for (int i = 0; i < rowBoard; ++i) {
        if(i>=9) cout<<"\t\t"<< i+1  << " ";
        else cout<<"\t\t" << i+1 << "  ";
        for (int j = 0; j < rowBoard; ++j) {
            cout<<boardMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Board::checkValidPlay(int rowSelection, int columnSelection, char colorPlayer){
    bool valid = false;
    char opponent = (colorPlayer == '-') ? '*' : '-';
    // Validar si la posicion seleccionada esta dentro del tablero
    if(rowSelection>=0 && rowSelection<=rowBoard-1 && columnSelection>=0 && columnSelection<rowBoard && boardMatrix[rowSelection][columnSelection]=='.'){
        //                      Se valida encierros

        /*                     Vertical hacia arriba
         * En este condicional se valida que la posicion no este en la parte superior del tablero
         * y a la vez se valida si la ficha arriba de esa posicion es del oponente, si es asi
         * entonces ingresa a un for para buscar una ficha del jugador actual
        */
        //                     Busca la posicion arriba que indico el usuario si la ficha es del oponente
        if(rowSelection>=0 && boardMatrix[rowSelection-1][columnSelection]==opponent){
            /*Inicia un for para recorrer desde la ficha del oponente hacia arriba para buscar otra ficha de
            si mismo*/
            for (int i = rowSelection-1; i >= 0; i--) {
                /* En este condicional se verifica si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    valid = true;
                    break;
                }
            }
        }
        /*                            Vertical hacia abajo
         * Se hace el proceso contrario del condicional anterior, manera de restar sumamos y aqui
         * usamos el total de filas que hay en el tablero para poder hacer la validacion y verificar que
         * no sea la ultima fila del tablero
         */
        if(rowSelection>=0 && rowSelection<rowBoard-1 && boardMatrix[rowSelection+1][columnSelection]==opponent){
            for (int i = rowSelection+1; i <rowBoard-1; i++) {
                /* En este condicional se busca si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    /* Si el condicional anterior se cumple entonces ingresa a un for que permite
                     * recorrer la fila desde la posicion de esa otra ficha del jugador que hace
                     * el encierro hacia arriba para cambiar las fichas del oponente.
                    */
                    valid = true;
                    break;
                }
            }
        }

        /*                            Horizontal hacia la derecha
         * En este condicional se valida que no este en la ultima columna del tablero
        */
        if(columnSelection>=0 && columnSelection<rowBoard-1 && boardMatrix[rowSelection][columnSelection+1]==opponent){
            for (int j = columnSelection+1; j <rowBoard; j++) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    valid = true;
                    break;
                }
            }
        }

        /*                            Horizontal hacia la izquierda
         * En este condicional se valida que no este en la primera columna del tablero
        */
        if(columnSelection>=0 && columnSelection<=rowBoard-1 && boardMatrix[rowSelection][columnSelection-1]==opponent){
            for (int j = columnSelection-1; j >= 0; j--) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    valid = true;
                    break;
                }
            }
        }

        /*                            Diagonal hacia la parte superior izquierda
         * En este condicional se valida que no este en la esquina superior izquierda del tablero
        */
        if(rowSelection>0 && columnSelection>0 && boardMatrix[rowSelection-1][columnSelection-1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection-1;

            while (i>=0 && j>=0 && j<=rowBoard-1) {
                if(boardMatrix[i][j]==colorPlayer){
                    valid = true;
                    break;
                }
                i--;
                j--;
            }
        }

        /*                            Diagonal hacia la parte superior derecha
         * En este condicional se valida que no este en la esquina superior derecha del tablero
        */
        if(rowSelection<=rowBoard-1 && columnSelection<rowBoard-1 && boardMatrix[rowSelection-1][columnSelection+1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection+1;

            while (i>=0 && i<rowBoard-1 && j<rowBoard-1) {
                if(boardMatrix[i][j]==colorPlayer){
                    valid = true;
                    break;
                }
                i--;
                j++;
            }
        }

        /*                            Diagonal hacia la parte inferior izquierda
         * En este condicional se valida que no este en la esquina inferior izquiera del tablero
        */
        if(rowSelection<rowBoard-1 && columnSelection<=rowBoard-1 && boardMatrix[rowSelection+1][columnSelection-1]==opponent){
            int i= rowSelection+1;
            int j= columnSelection-1;

            while (i<rowBoard-1 && j>=0) {
                if(boardMatrix[i][j]==colorPlayer){
                    valid = true;
                    break;
                }
                i++;
                j--;
            }
        }

        /*                            Diagonal hacia la parte inferior derecha
         * En este condicional se valida que no este en la esquina inferior derecha del tablero
        */

        if(rowSelection<rowBoard-1 && columnSelection<rowBoard-1 && boardMatrix[rowSelection+1][columnSelection+1]==opponent){
            int i= rowSelection+1;
            int j= columnSelection+1;

            while (i<rowBoard && j<rowBoard) {
                if(boardMatrix[i][j]==colorPlayer){
                    valid = true;
                    break;
                }
                i++;
                j++;
            }
        }

    }

    if(valid==false) cout <<"\t\t Posicion invalida, no hay encierros" << endl;
    return valid;

}

int Board::checkAvailableMoves(char colorPlayer){
    int availablesMoves = 0;
    char opponent = (colorPlayer == '-') ? '*' : '-';

    // Recorre todo el tablero
    for (int row = 0; row < rowBoard; row++) {
        for (int column = 0; column < rowBoard; column++)
        {
            // Valida o busca una posicion donde este la ficha del jugador

            if(boardMatrix[row][column]==colorPlayer){
                /*
                 Valida si hay ficha oponente arriba del jugador para un posible encierro
                */
                if(row>0 && boardMatrix[row-1][column]==opponent){
                    availablesMoves++;
                }
                // Valida si hay ficha oponente abajo del jugador para un posible encierro
                if(row<rowBoard-1 && boardMatrix[row+1][column]==opponent){
                    availablesMoves++;
                }
                //Valida si hay ficha oponente de manera horizontal izq del jugador para un posible encierro
                if(column<rowBoard && boardMatrix[row][column-1]==opponent){
                    availablesMoves++;
                }
                //Valida si hay ficha oponente de manera horizontal der del jugador para un posible encierro
                if(column>0 && boardMatrix[row][column+1]==opponent){
                    availablesMoves++;
                }
                //Valida si es posible encierro de manera diagonal hacia la parte superior izq
                if(row>=0 && column>=0 && boardMatrix[row-1][column-1]==opponent){
                    availablesMoves++;
                }
                //Valida si es posible encierro de manera diagonal hacia la parte superior der
                if(row>=0 && column>=0 && boardMatrix[row-1][column+1]==opponent){
                    availablesMoves++;
                }
                //Valida si es posible encierro de manera diagonal hacia la parte inferior izq
                if(row>=0 && column>=0 && row+1<rowBoard && column+1<rowBoard && boardMatrix[row+1][column-1]==opponent){
                    availablesMoves++;
                }
                //Valida si es posible encierro de manera diagonal hacia la parte inferior derecha
                if(row>=0 && column>=0 && row+1<rowBoard && column+1<rowBoard && boardMatrix[row+1][column+1]==opponent){
                    availablesMoves++;
                }
            }
        }
    }

    return availablesMoves;
}

bool Board::checkFullBoard(){

    for (int i = 0; i < rowBoard; ++i) {
        for (int j = 0; j < rowBoard; ++j) {
            if(boardMatrix[i][j]=='.')
                return false;
        }
    }

    return true;
}

void Board::saveGame(){

    ofstream games("games.txt", ios::app);
    string data;
    if(!games.is_open()){
        cerr << "No se pudo abrir el archivo, valide por favor."<<endl;
    }else{
        games<<data;
    }
}

int Board::getRow(){
    return rowBoard;
}

char** Board::getBoard(){
    return boardMatrix;
}

/*Referencias

https://es.stackoverflow.com/questions/51771/crear-una-matriz-de-objetos-din%C3%A1mica-en-c
https://mauricioavilesc.blogspot.com/2015/08/matriz-dinamica-en-c.html
d
*/
