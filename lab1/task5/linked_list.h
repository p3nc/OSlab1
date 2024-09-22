#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Структура для вузла списку
typedef struct Node {
    int data;           // Дані вузла
    struct Node *next;  // Вказівник на наступний вузол
} Node;

// Структура для списку
typedef struct {
    Node *head;         // Вказівник на голову списку
    int size;           // Розмір списку
} LinkedList;

// Створення нового списку
LinkedList* create_list();

// Додавання елемента в кінець списку
void add(LinkedList *list, int item);

// Вставка елемента в середину списку
void insert(LinkedList *list, int index, int item);

// Отримання кількості елементів у списку
int size(LinkedList *list);

// Видалення елемента по індексу
void remove_at(LinkedList *list, int index);

// Зміна значення існуючого елемента
void set(LinkedList *list, int index, int item);

// Отримання значення елемента за індексом
int get(LinkedList *list, int index);

// Звільнення пам'яті списку
void free_list(LinkedList *list);

#endif
