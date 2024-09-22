#include <stdio.h>
#include "math_series.h"

int main() {
    double a, b, epsilon;
    int n;

    // Введення початкових значень
    printf("Enter the interval bounds a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the number of parts n: ");
    scanf("%d", &n);

    printf("Enter the accuracy epsilon: ");
    scanf("%lf", &epsilon);

    // Вичислення результат
    double length = curve_length(a, b, n, epsilon);

    printf("Length of the curve: %.10lf\n", length);

    return 0;
}

