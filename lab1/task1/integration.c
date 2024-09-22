#include "math_series.h"
#include <math.h>

// Функція f'(x) = sin(x^2) / (1 + cos(x^3))
double derivative_function(double x, double epsilon) {
    double sin_x2 = taylor_sin(x * x, epsilon);
    double cos_x3 = taylor_cos(x * x * x, epsilon);
    return sin_x2 / (1 + cos_x3);
}

// Чисельне обчислення інтегралу для довжини кривої
double curve_length(double a, double b, int n, double epsilon) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        double f_prime = derivative_function(x, epsilon);
        sum += sqrt(1 + f_prime * f_prime);
    }
    return sum * h;
}
