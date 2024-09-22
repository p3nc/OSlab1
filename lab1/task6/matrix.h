#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;        // Кількість рядків
    int cols;        // Кількість стовпців
    double **data;   // Двовимірний масив для зберігання елементів матриці
} Matrix;

// Створення матриці
Matrix* create_matrix(int rows, int cols);

// Звільнення пам'яті матриці
void free_matrix(Matrix *matrix);

// Зміна розмірів матриці зі збереженням вмісту
Matrix* resize_matrix(Matrix *matrix, int new_rows, int new_cols);

// Встановлення значення елемента матриці
void set_element(Matrix *matrix, int row, int col, double value);

// Отримання значення елемента матриці
double get_element(Matrix *matrix, int row, int col);

// Виведення матриці на екран
void print_matrix(Matrix *matrix);

// Збереження матриці у файл
void save_matrix_to_file(Matrix *matrix, const char *filename);

// Зчитування матриці з файлу
Matrix* load_matrix_from_file(const char *filename);

// Матричні операції
Matrix* add_matrices(Matrix *a, Matrix *b);
Matrix* subtract_matrices(Matrix *a, Matrix *b);
Matrix* multiply_matrix_by_number(Matrix *matrix, double num);
Matrix* multiply_matrices(Matrix *a, Matrix *b);
Matrix* transpose_matrix(Matrix *matrix);

#endif
