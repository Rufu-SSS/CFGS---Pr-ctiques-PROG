
#include <iostream>
#include <string>
// Incluir les llibreries que fan falta
using namespace std;
int askNumber(int high, int low = 1);
int main()
{
	int number = askNumber(5);
	cout << "Thanks for entering: " << number << "\n\n";
	number = askNumber(10, 5);

	cout << "Thanks for entering: " << number << "\n\n";
	return 0;
}
