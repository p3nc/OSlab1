#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 30
#define NAME_LENGTH 12

// Структура для зберігання інформації про студента
typedef struct {
    char surname[NAME_LENGTH];  // прізвище студента
    int group;                  // номер групи (1-4)
    int web_tech;               // бали за Веб-технології
    int ukr_language;           // бали за Укр. мову
    int project_design;         // бали за Проектування інформаційних систем
} Student;

// Функції для обробки запитів
void print_debtors(Student students[], int n);
double percentage_of_excellent_good_students(Student students[], int n);
const char* best_subject(Student students[], int n);
int worst_performance_group(Student students[], int n);

#endif
