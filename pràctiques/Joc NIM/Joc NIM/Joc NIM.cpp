// Joc NIM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <string>
#include <iostream>
using namespace std;
// Variables globals perque funcioni tot
int nombre = 0;
int nombre2 = 0;
char resposta;
string jugador1;
string jugador2;
bool play = true;

int main() {
    play = true;
    cout << "Benvingut al Joc de Nim" << endl;

    cout << endl << "Digues el nombre inicial amb que es jugara:  ";
    cin >> nombre;
    cout << "Quins son els noms dels jugadors?" << endl;
    cout << "Jugador 1: ";
    cin >> jugador1;
    cout << "Jugador 2: ";
    cin >> jugador2;
   
    cout << "El nombre inicial es " << nombre << endl << endl;
  
    while (true) {
        int jugResta1, jugResta2;
        cout << jugador1 << "Quin nombre vols restar a " << nombre << " ?" << endl;
        while (true){
            switch (jugResta1) {
            case 1:
                cout << "Restant numero 1 a " << nombre << endl;
                nombre -= 1;
                break;
            case 2:
                cout << "Restant numero 2 a " << nombre << endl;
                nombre -= 2;
                break;
            default:
                cout << "Entrada incorrecta, sisplau posi els numeros 1 o 2." << endl;
                continue;
            }
        }
    }
    /*while (nombre != 0) {
            if (resposta == 'a') {
            cout << "restant 1 a " << nombre << " . . ." << endl;
            nombre = nombre - 1;
            cout << "El nombre ara es: " << nombre << endl;
        }
        if (resposta == 'b') {
            cout << "restant 2 a " << nombre << " . . ." << endl;
            nombre = nombre - 2;
            cout << "El nombre ara es: " << nombre << endl;
            if (resposta == 0) {
                cout << "Felicitats, has arribat a 0!" << endl;
                break;
            }
        }
    }
    */
}


   
/* 

*/


  





