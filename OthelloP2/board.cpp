#include "board.h"

board::board(int row, int column)
{
    rowBoard = row;
    boardMatrix = new char*[row];
    for(int i=0; i<row; i++)
        boardMatrix[i] = new char[column];

    //Rellenado de tablero y puesta de fichas centrales
    int fi=row/2; int col=row/2; char co='*';
    for (int f = 0; f < row; ++f) {
        for (int c = 0; c < column; ++c) {
            if(f==fi&&c==col&&co=='*'){
                boardMatrix[f][c]='*';
                boardMatrix[f][++c]='-';
                fi ++; co='-';
            }else if(f==fi&&c==col&&co!='*'){
                boardMatrix[f][--c]='-';
                boardMatrix[f][++c]='*';
            }else{
                boardMatrix[f][c]='_';
            }
        }
    }
}

board::~board(){
    for (int i = 0; i < rowBoard; ++i) {
        delete[] boardMatrix[i];
    }
}

void board::placeCard(int rowSelection, int columnSelection, char colorPlayer ){
    boardMatrix[rowSelection][columnSelection] = colorPlayer;
}

void board::showBoard(){

    for (int i = 0; i < rowBoard; ++i) {
        for (int j = 0; j < rowBoard; ++j) {
            cout<<"\t\t"<<boardMatrix[i][j];
        }
        cout<<endl;
    }
}

bool board::checkValidPlay(int rowSelection, int columnSelection, char colorPlayer){

    char opponent = (colorPlayer == '-') ? '+' : '-';
    // Validar si la posicion seleccionada esta dentro del tablero
    if(0<rowSelection-1<rowBoard && 0<columnSelection-1<rowBoard){
        //                      Se valida encierros

        /*                     Vertical hacia arriba
         * En este condicional se valida que la posicion no este en la parte superior del tablero
         * y a la vez se valida si la ficha arriba de esa posicion es del oponente, si es asi
         * entonces ingresa a un for para buscar una ficha del jugador actual
        */
        if(rowSelection-1>=0 && boardMatrix[rowSelection-1][columnSelection]==opponent){
            for (int i = rowSelection-1; i >= 0; i--) {
                /* En este condicional se busca si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    /* Si el condicional anterior se cumple entonces ingresa a un for que permite
                     * recorrer la fila desde la posicion de esa otra ficha del jugador que hace
                     * el encierro hacia abajo para cambiar las fichas del oponente.
                    */
                    for (int j = rowSelection-1; j>i; j--) {
                        placeCard(i,columnSelection,colorPlayer);
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
        if(rowSelection+1<rowBoard && boardMatrix[rowSelection+1][columnSelection]==opponent){
            for (int i = rowSelection+1; i <rowBoard; i++) {
                /* En este condicional se busca si la siguiente fichas desde la posicion del rival
                 * es una ficha del jugador actual para buscar el encierro
                */
                if(boardMatrix[i][columnSelection]==colorPlayer){
                    /* Si el condicional anterior se cumple entonces ingresa a un for que permite
                     * recorrer la fila desde la posicion de esa otra ficha del jugador que hace
                     * el encierro hacia arriba para cambiar las fichas del oponente.
                    */
                    for (int j = rowSelection+1; j<i; j++) {
                        placeCard(i,columnSelection,colorPlayer);
                    }
                    break;
                }
            }
        }

        /*                            Horizontal hacia la izquierda
         * En este condicional se valida que no este en la primera columna del tablero
        */
        if(columnSelection-1>=0 && boardMatrix[rowSelection][columnSelection-1]==opponent){
            for (int j = columnSelection-1; j >= 0; j--) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    for (int i = columnSelection-1; i>j ; i--) {
                        placeCard(rowSelection,i,colorPlayer);
                    }
                    break;
                }
            }
        }

        /*                            Horizontal hacia la izquierda
         * En este condicional se valida que no este en la ultima columna del tablero
        */
        if(columnSelection+1<rowBoard && boardMatrix[rowSelection][columnSelection+1]==opponent){
            for (int j = columnSelection+1; j <rowBoard; j++) {
                if(boardMatrix[rowSelection][j]==colorPlayer){
                    for (int i = columnSelection+1; i<j ; i++) {
                        placeCard(rowSelection,i,colorPlayer);
                    }
                    break;
                }
            }
        }


        /*                            Diagonal hacia la parte superior izquierda
         * En este condicional se valida que no este en la esquina superior izquierda del tablero
        */
        if(rowSelection-1>=0 && columnSelection-1>=0 && boardMatrix[rowSelection-1][columnSelection-1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection-1;

            while (i>=0 && j>=0) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection-1, y = columnSelection-1; x>i && y>j; x--,y--) {
                        placeCard(x,y,colorPlayer);
                    }
                    break;
                }
                i--;
                j--;
            }
        }

        /*                            Diagonal hacia la parte inferior derecha
         * En este condicional se valida que no este en la esquina inferior derecha del tablero
        */

        if(rowSelection+1<rowBoard && columnSelection+1<rowBoard && boardMatrix[rowSelection+1][columnSelection+1]==opponent){
            int i= rowSelection+1;
            int j= columnSelection+1;

            while (i<rowBoard && j<rowBoard) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection+1, y = columnSelection+1; x<i && y<j; x++,y++) {
                        placeCard(x,y,colorPlayer);
                    }
                    break;
                }
                i++;
                j++;
            }
        }

        /*                            Diagonal hacia la parte superior derecha
         * En este condicional se valida que no este en la esquina superior derecha del tablero
        */
        if(rowSelection-1>=0 && columnSelection+1<rowBoard && boardMatrix[rowSelection-1][columnSelection+1]==opponent){
            int i= rowSelection-1;
            int j= columnSelection+1;

            while (i>=0 && j<rowBoard) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection-1, y = columnSelection+1; x>i && y>j; x--,y++) {
                        placeCard(x,y,colorPlayer);
                    }
                    break;
                }
                i--;
                j++;
            }
        }

        /*                            Diagonal hacia la parte inferior izquierda
         * En este condicional se valida que no este en la esquina inferior izquiera del tablero
        */
        if(rowSelection+1<rowBoard && columnSelection-1>=0 && boardMatrix[rowSelection+1][columnSelection-1]==opponent){
            int i= rowSelection+1;
            int j= columnSelection-1;

            while (i<rowBoard && j>=0) {
                if(boardMatrix[i][j]==colorPlayer){
                    for (int x = rowSelection+1, y = columnSelection-1; x>i && y>j; x++,y--) {
                        placeCard(x,y,colorPlayer);
                    }
                    break;
                }
                i++;
                j--;
            }
        }
        return true;
    }else{
        return false;
    }
}

void board::saveGame(){

    ofstream games("games.txt", ios::app);
    string data;
    if(!games.is_open()){
        cerr << "No se pudo abrir el archivo, valide por favor."<<endl;
    }else{
        games<<data;
    }
}

/*Referencias

https://es.stackoverflow.com/questions/51771/crear-una-matriz-de-objetos-din%C3%A1mica-en-c
https://mauricioavilesc.blogspot.com/2015/08/matriz-dinamica-en-c.html
d
*/
