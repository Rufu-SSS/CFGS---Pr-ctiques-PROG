#include "equaciosegongrau.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <complex>

using namespace std;

//Calcula el discriminant
double QuadraticEquation::discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

// Resol equacio quadratica
string QuadraticEquation::solve(double a, double b, double c) {
    // calcula discriminnat
    double discriminant_value = discriminant(a, b, c);

    // si el discriminant es mes gran que 0, tenim dues solucions
    if (discriminant_value > 0) {
        double x1 = (-b + sqrt(discriminant_value)) / (2 * a);
        double x2 = (-b - sqrt(discriminant_value)) / (2 * a);

        stringstream ss;
        ss << "Solucions reals: x1 = " << x1 << ", x2 = " << x2;
        return ss.str();
    }
    // Si es 0, tenim una sola solucio
    else if (discriminant_value == 0) {
        double x = -b / (2 * a);

        stringstream ss;
        ss << "Solucio real: x = " << x;
        return ss.str();
    }
    // Si es menor a 0 tenim diferents solucions
    else {
        complex<double> x1(-b / (2 * a), sqrt(-discriminant_value) / (2 * a));
        complex<double> x2(-b / (2 * a), -sqrt(-discriminant_value) / (2 * a));

        stringstream ss;
        ss << "Solucions complexes: x1 = " << x1 << ", x2 = " << x2;
        return ss.str();
    }
}
