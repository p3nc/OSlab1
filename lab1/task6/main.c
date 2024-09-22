#include <stdio.h>
#include "matrix.h"

int main() {
    // 1. Створення матриці 2x2 і заповнення її значеннями
    Matrix *matrix1 = create_matrix(2, 2);
    set_element(matrix1, 0, 0, 1.0);
    set_element(matrix1, 0, 1, 2.0);
    set_element(matrix1, 1, 0, 3.0);
    set_element(matrix1, 1, 1, 4.0);
    printf("Initial Matrix 1:\n");
    print_matrix(matrix1);

    // 2. Створення іншої матриці 2x2 для математичних операцій
    Matrix *matrix2 = create_matrix(2, 2);
    set_element(matrix2, 0, 0, 5.0);
    set_element(matrix2, 0, 1, 6.0);
    set_element(matrix2, 1, 0, 7.0);
    set_element(matrix2, 1, 1, 8.0);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // 3. Додавання матриць
    Matrix *sum_matrix = add_matrices(matrix1, matrix2);
    printf("Sum of matrices:\n");
    print_matrix(sum_matrix);

    // 4. Віднімання матриць
    Matrix *diff_matrix = subtract_matrices(matrix1, matrix2);
    printf("Difference of matrices:\n");
    print_matrix(diff_matrix);

    // 5. Множення матриці на число
    Matrix *mult_by_num = multiply_matrix_by_number(matrix1, 2.5);
    printf("Matrix 1 multiplied by 2.5:\n");
    print_matrix(mult_by_num);

    // 6. Множення матриць
    Matrix *mult_matrix = multiply_matrices(matrix1, matrix2);
    if (mult_matrix) {
        printf("Product of matrices:\n");
        print_matrix(mult_matrix);
    }

    // 7. Транспонування матриці 1
    Matrix *transposed_matrix = transpose_matrix(matrix1);
    printf("Transposed Matrix 1:\n");
    print_matrix(transposed_matrix);

    // 8. Зміна розміру матриці
    printf("Resizing Matrix 1 to 3x3:\n");
    matrix1 = resize_matrix(matrix1, 3, 3);
    set_element(matrix1, 2, 2, 9.0); // Додамо новий елемент у змінену матрицю
    print_matrix(matrix1);

    // 9. Запис матриці у файл
    save_matrix_to_file(matrix1, "matrix1.txt");
    printf("Matrix 1 saved to 'matrix1.txt'\n");

    // 10. Зчитування матриці з файлу
    Matrix *loaded_matrix = load_matrix_from_file("matrix1.txt");
    if (loaded_matrix) {
        printf("Matrix loaded from 'matrix1.txt':\n");
        print_matrix(loaded_matrix);
    }

    // 11. Виведення розміру матриці
    printf("Size of Matrix 1: %d x %d\n", matrix1->rows, matrix1->cols);

    // 12. Звільнення пам'яті
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(sum_matrix);
    free_matrix(diff_matrix);
    free_matrix(mult_by_num);
    free_matrix(mult_matrix);
    free_matrix(transposed_matrix);
    free_matrix(loaded_matrix);

    return 0;
}
