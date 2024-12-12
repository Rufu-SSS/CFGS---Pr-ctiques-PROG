// multitasca.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int main()
{
    int PUNTUACIO;
    std::cout << "Escriu una puntuacio!\n";
    cin >> PUNTUACIO;
    PUNTUACIO = PUNTUACIO + 200;
    std::cout << "La puntuacio es de " << PUNTUACIO << endl;

        int videsOriginal, videsCopies;
    std::cout << "Escriu un numero de vides!" << endl;
    cin >> videsOriginal;
    videsCopies = videsOriginal;
    std::cout << "Les copies son " << videsCopies << endl;
    videsOriginal = videsOriginal * 10;
    std::cout << "Les vides son " << videsOriginal << endl;
   
    int variable;
    std::cout << "Assigna el valor 4294967295 a la variable anterior" << endl;
    cin >> variable;
    variable = 4294967295;
    variable = 4294967295 + 1;
    std::cout << "El valor obtingut és " << variable;
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
