#include "array_operations.h"
#include <math.h>  // для fabs

// Функція для обчислення середнього значення
double calculate_average(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Функція для підрахунку кількості елементів, більших за середнє
int count_greater_than_average(double arr[], int n) {
    double average = calculate_average(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }
    return count;
}

// Функція для знаходження суми абсолютних значень після першого від'ємного елементу
double sum_abs_after_first_negative(double arr[], int n) {
    int found_negative = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && !found_negative) {
            found_negative = 1;
        } else if (found_negative) {
            sum += fabs(arr[i]);
        }
    }
    return sum;
}
