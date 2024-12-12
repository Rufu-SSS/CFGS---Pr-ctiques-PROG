#pragma once
#include <string>
#include <complex>

class QuadraticEquation {
public:
    // Fa l'equacio de segon grau
    static std::string solve(double a, double b, double c);

    // Método que calcula el discriminante
    static double discriminant(double a, double b, double c);
};

