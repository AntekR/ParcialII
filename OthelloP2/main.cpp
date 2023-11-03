#include <iostream>
#include <game.h>
#include <board.h>
#include <player.h>

using namespace std;

int main()
{
    int choice; string player1, player2; char playColor1, playColor2;
    cout<<"\t\tOthello"<<endl;

    cout<<"\t 1. Iniciar juego"<<endl;
    cout<<"\t 2. Cargar registro de partidas"<<endl;
    cout<<"\t Selecciona una opcion: ";
    cin>> choice;

    switch (choice) {
    case 1:
        cout<<"\t\tBienvenido Jugadores"<<endl;
        cout<<"\t Antes de inicar el juego, ingresen su nombre y color con el cual van a jugar"<<endl;
        cout<<"\t Recuerden que sus nombres no pueden ser iguales y solo hay dos colores: blanco (B) y negro (N)."<<endl;

        cout<<"\t Jugador 1 "<<endl;
        cout<<"\t Nombre: ";
        cin>> player1;
        cout<<"\t Color: ";
        cin>> playColor1;

        cout<<"\t Jugador 2 "<<endl;
        cout<<"\t Nombre: ";
        cin>> player2;
        cout<<"\t Color: ";
        cin>> playColor2;

        //while()
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}
