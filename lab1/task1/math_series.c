#include "math_series.h"
#include <math.h>

// Обчислення синуса через ряд Тейлора
double taylor_sin(double x, double epsilon) {
    double term = x;  // перший член ряду
    double sum = term;
    int n = 1;
    while (fabs(term) > epsilon) {
        term *= -x * x / (2 * n * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

// Обчислення косинуса через ряд Тейлора
double taylor_cos(double x, double epsilon) {
    double term = 1.0;  // перший член ряду
    double sum = term;
    int n = 1;
    while (fabs(term) > epsilon) {
        term *= -x * x / (2 * n * (2 * n - 1));
        sum += term;
        n++;
    }
    return sum;
}
