#include "student.h"
#include <stdio.h>

// Функція для виведення прізвищ студентів, які мають заборгованості
void print_debtors(Student students[], int n) {
    printf("Студенти з заборгованістю:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].web_tech < 60 || students[i].ukr_language < 60 || students[i].project_design < 60) {
            printf("%s\n", students[i].surname);
        }
    }
}

// Функція для обчислення проценту студентів, що здали всі екзамени на відмінно або добре (бали >= 75)
double percentage_of_excellent_good_students(Student students[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].web_tech >= 75 && students[i].ukr_language >= 75 && students[i].project_design >= 75) {
            count++;
        }
    }
    return (double)count / n * 100;
}

// Функція для визначення предмета, який здали найкраще
const char* best_subject(Student students[], int n) {
    int web_tech_sum = 0, ukr_language_sum = 0, project_design_sum = 0;

    for (int i = 0; i < n; i++) {
        web_tech_sum += students[i].web_tech;
        ukr_language_sum += students[i].ukr_language;
        project_design_sum += students[i].project_design;
    }

    if (web_tech_sum >= ukr_language_sum && web_tech_sum >= project_design_sum) {
        return "Веб-технології";
    } else if (ukr_language_sum >= project_design_sum) {
        return "Укр. мова";
    } else {
        return "Проектування інформаційних систем";
    }
}

// Функція для визначення групи з найгіршою успішністю
int worst_performance_group(Student students[], int n) {
    int group_sums[4] = {0, 0, 0, 0};
    int group_counts[4] = {0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        int group_index = students[i].group - 1;
        group_sums[group_index] += students[i].web_tech + students[i].ukr_language + students[i].project_design;
        group_counts[group_index]++;
    }

    int worst_group = 0;
    double worst_average = (double)group_sums[0] / group_counts[0];

    for (int i = 1; i < 4; i++) {
        double average = (double)group_sums[i] / group_counts[i];
        if (average < worst_average) {
            worst_average = average;
            worst_group = i;
        }
    }

    return worst_group + 1;
}
