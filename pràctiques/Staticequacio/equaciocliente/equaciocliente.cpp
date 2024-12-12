// main.cpp
#include <iostream>
#include "../Equaciosegongrau/equaciosegongrau.h"

using namespace std;

int main() {
    double a = 0, b = 0, c = 0;  

    cout << "Dona valor a la lletra a: ";
    cin >> a;

    cout << "Dona valor a la lletra b: ";
    cin >> b;

    cout << "Dona valor a la lletra c: ";
    cin >> c;

    string result = QuadraticEquation::solve(a, b, c);

    
    cout << result << std::endl;

    return 0;
}
