#include <iostream>
#include <cmath>
#define EPSILON 0.0001
using namespace std;

// Fungsi yang ingin dicari akarnya
double f(double x) {
    return x*x*x - x - 1;  // f(x) = x^3 - x - 1
}

// Metode Bagi Dua
void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Bisection: f(a) dan f(b) harus berbeda tanda.\n";
        return;
    }

    double c;
    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Akar (Bisection): " << c << endl;
}

// Metode Regula-Falsi
void regulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Regula-Falsi: f(a) dan f(b) harus berbeda tanda.\n";
        return;
    }
    
    double c = a;
    for (int i = 0; i < 100; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (fabs(f(c)) < EPSILON)
            break;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Akar (Regula-Falsi): " << c << endl;
}

// Metode Secant
void secant(double x0, double x1) {
    double x2;
    for (int i = 0; i < 100; i++) {
        if (fabs(f(x1) - f(x0)) < EPSILON) break;

        x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));

        if (fabs(f(x2)) < EPSILON)
            break;

        x0 = x1;
        x1 = x2;
    }
    cout << "Akar (Secant): " << x2 << endl;
}

// Main program
int main() {
    double a = 1, b = 2;  // Interval
    bisection(a, b);
    regulaFalsi(a, b);
    secant(a, b);
    return 0;
}