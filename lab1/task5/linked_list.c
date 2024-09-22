#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Ініціалізація нового списку
LinkedList* create_list() {
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Створення нового вузла
Node* create_node(int item) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    return new_node;
}

// Додавання елемента в кінець списку
void add(LinkedList *list, int item) {
    Node *new_node = create_node(item);

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// Вставка елемента в середину списку
void insert(LinkedList *list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }

    Node *new_node = create_node(item);

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->size++;
}

// Отримання кількості елементів у списку
int size(LinkedList *list) {
    return list->size;
}

// Видалення елемента по індексу
void remove_at(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }

    Node *to_delete;
    if (index == 0) {
        to_delete = list->head;
        list->head = list->head->next;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        to_delete = current->next;
        current->next = current->next->next;
    }

    free(to_delete);
    list->size--;
}

// Зміна значення існуючого елемента
void set(LinkedList *list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = item;
}

// Отримання значення елемента за індексом
int get(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Помилка: некоректний індекс\n");
        return -1;  // Помилкове значення
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Звільнення пам'яті списку
void free_list(LinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
