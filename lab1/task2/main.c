#include <stdio.h>
#include "array_operations.h"

int main() {
    int n;

    // Введення розміру масиву
    printf("Type number of elements: ");
    scanf("%d", &n);

    double arr[n];

    // Введення елементів масиву
    printf("Type elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Підрахунок кількості елементів більших за середнє значення
    int r = count_greater_than_average(arr, n);
    printf("Number of elements greater than the average: %d\n", r);

    // Обчислення суми абсолютних значень після першого від'ємного елементу
    double sum_abs = sum_abs_after_first_negative(arr, n);
    printf("Sum of absolute values after the first negative element: %.2f\n", sum_abs);

    return 0;
}
