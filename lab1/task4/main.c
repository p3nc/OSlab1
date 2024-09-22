#include <stdio.h>
#include "array_list.h"

int main() {
    ArrayList *list = create_list();

    // Додавання елементів
    add(list, 10);
    add(list, 20);
    add(list, 30);
    printf("Number of elements after adding: %d\n", size(list));


    // Вставка елемента
    insert(list, 1, 15);
    printf("Elements after insertion: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n");

    // Зміна значення
    set(list, 2, 25);
    printf("Elements after modification: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n");

    // Видалення елемента
    remove_at(list, 1);
    printf("Elements after removal: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n");

    // Звільнення пам'яті
    free_list(list);

    return 0;
}
