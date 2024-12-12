// ConsoleApplication24-09.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int vida;
	cout << "Quants punt de vida vols que tingui el personatge?" << endl;
	cin >> vida;
	cout << "El personatge te " << vida << " punts de vida" << endl << endl;
	srand((unsigned)time(NULL));
	int num, n;
	cout << "Oh no! Ha aparescut un monstre molt perillos!" << endl;
	cout << "Tira un dau de 8 cares per veure el dany que reps! (escrivint tirar)" << endl << endl;
	cin >> num;
	n = rand() % 8 + 1;
	cout << "El jugador rep " << n << " punts de dany" << endl << endl;
	if (vida-n<=0) {
		cout << "El jugador ha mort" << endl << "S'ha acabat el joc" << endl;
	}
	else {
		cout << "El jugador ha quedat amb " << vida - n << " punts de vida" << endl << endl;

	}

	system("PAUSE");
	
	return EXIT_SUCCESS;

}
