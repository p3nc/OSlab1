#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Створення матриці
Matrix* create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**) malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double*) malloc(cols * sizeof(double));
    }
    return matrix;
}

// Звільнення пам'яті матриці
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Зміна розмірів матриці зі збереженням вмісту
Matrix* resize_matrix(Matrix *matrix, int new_rows, int new_cols) {
    Matrix *new_matrix = create_matrix(new_rows, new_cols);

    for (int i = 0; i < matrix->rows && i < new_rows; i++) {
        for (int j = 0; j < matrix->cols && j < new_cols; j++) {
            new_matrix->data[i][j] = matrix->data[i][j];
        }
    }

    free_matrix(matrix);
    return new_matrix;
}

// Встановлення значення елемента матриці
void set_element(Matrix *matrix, int row, int col, double value) {
    if (row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        matrix->data[row][col] = value;
    } else {
        printf("Помилка: некоректний індекс\n");
    }
}

// Отримання значення елемента матриці
double get_element(Matrix *matrix, int row, int col) {
    if (row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        return matrix->data[row][col];
    } else {
        printf("Помилка: некоректний індекс\n");
        return 0.0;
    }
}

// Виведення матриці на екран
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Збереження матриці у файл
void save_matrix_to_file(Matrix *matrix, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Помилка при відкритті файлу\n");
        return;
    }

    fprintf(file, "%d %d\n", matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            fprintf(file, "%lf ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Зчитування матриці з файлу
Matrix* load_matrix_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка при відкритті файлу\n");
        return NULL;
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    Matrix *matrix = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%lf", &matrix->data[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

// Додавання матриць
Matrix* add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Помилка: матриці мають різні розміри\n");
        return NULL;
    }

    Matrix *result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

// Віднімання матриць
Matrix* subtract_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Помилка: матриці мають різні розміри\n");
        return NULL;
    }

    Matrix *result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }

    return result;
}

// Множення матриці на число
Matrix* multiply_matrix_by_number(Matrix *matrix, double num) {
    Matrix *result = create_matrix(matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[i][j] = matrix->data[i][j] * num;
        }
    }
    return result;
}

// Множення матриць
Matrix* multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Помилка: кількість стовпців першої матриці не дорівнює кількості рядків другої матриці\n");
        return NULL;
    }

    Matrix *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// Транспонування матриці
Matrix* transpose_matrix(Matrix *matrix) {
    Matrix *result = create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}
