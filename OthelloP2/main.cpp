#include <iostream>
#include "game.h"

using namespace std;


int main()
{

    int choice;
    string player1; string player2;
    char color1;
    char color2;
    int row;
    cout<<"\t\t\t\t Othello"<<endl;

    cout<<"\t\t\t 1. Iniciar juego"<<endl;
    cout<<"\t\t\t 2. Cargar registro de partidas"<<endl;
    cout<<"\t\t\t Selecciona una opcion: ";
    cin>> choice;

    switch (choice) {
    case 1:{

        cout<< endl << "\t\t\t\tBienvenido Jugadores"<<endl;
        cout<<"\t   Antes de inicar el juego, ingresen su nombre y color con el cual van a jugar"<<endl;
        cout<<"\t Recuerden que sus nombres no pueden ser iguales y solo hay dos colores: blanco (-) y negro (*)."<<endl;

        cout<<"\t Ingrese el tamano del tablero: ";
        cin >> row;

        cout<<"\t Jugador 1 "<<endl;
        cout<<"\t Nombre: ";
        cin>> player1;
        cout<<"\t Color: ";
        cin>> color1;

        cout<<"\t Jugador 2 "<<endl;
        cout<<"\t Nombre: ";
        cin>> player2;
        color2 = (color1=='-') ? '*' : '-';

        // Inicializacion de la variable

        Game g(row,player1,color1,player2,color2);

        //Tablero inicial
        cout << "\t\t!Empezo el juego!" << endl << "\t\t Tablero inicial" << endl;
        g.startGame();

        while (g.checkEnd() == Status::EN_JUEGO) {
            // Realizar un movimiento
            g.makeMove();
        }

        if(g.checkEnd()==Status::FINALIZADO){
            g.saveGame();
            cout << "Resultado de la partida actual" << endl;
            g.printResults();

        }
        break;
    }
    case 2:{
        Game g(row,player1,color1,player2,color2);
        cout << "\t\tPartidas registradas" << endl;
        g.loadGame();
        break;
    }
    default:
        //Opcion invalida
        cout << "Opcion invalida" << endl;
        break;
    }

    return 0;
}
