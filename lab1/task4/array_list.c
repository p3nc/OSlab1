#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

// Ініціалізація нового списку
ArrayList* create_list() {
    ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
    list->capacity = 4;  // Початкова ємність
    list->size = 0;
    list->data = (int*) malloc(list->capacity * sizeof(int));
    return list;
}

// Збільшення ємності масиву
void resize_if_needed(ArrayList *list) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int*) realloc(list->data, list->capacity * sizeof(int));
    }
}

// Додавання елемента в кінець списку
void add(ArrayList *list, int item) {
    resize_if_needed(list);
    list->data[list->size] = item;
    list->size++;
}

// Вставка елемента в середину списку
void insert(ArrayList *list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }

    resize_if_needed(list);

    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = item;
    list->size++;
}

// Отримання кількості елементів у списку
int size(ArrayList *list) {
    return list->size;
}

// Видалення елемента по індексу
void remove_at(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

// Зміна значення існуючого елемента
void set(ArrayList *list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }
    list->data[index] = item;
}

// Отримання значення елемента за індексом
int get(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return -1;  // Повертаємо помилкове значення
    }
    return list->data[index];
}

// Звільнення пам'яті списку
void free_list(ArrayList *list) {
    free(list->data);
    free(list);
}
