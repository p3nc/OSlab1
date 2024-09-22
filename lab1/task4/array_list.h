#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    int *data;      // Масив даних
    int capacity;   // Поточна ємність масиву
    int size;       // Кількість елементів у масиві
} ArrayList;

// Створення нового списку
ArrayList* create_list();

// Додавання елемента в кінець списку
void add(ArrayList *list, int item);

// Вставка елемента в середину списку
void insert(ArrayList *list, int index, int item);

// Отримання кількості елементів у списку
int size(ArrayList *list);

// Видалення елемента по індексу
void remove_at(ArrayList *list, int index);

// Зміна значення існуючого елемента
void set(ArrayList *list, int index, int item);

// Отримання значення елемента за індексом
int get(ArrayList *list, int index);

// Звільнення пам'яті списку
void free_list(ArrayList *list);

#endif
