#include <stdio.h>
#include "student.h"

int main() {
    int n;

    // Введення кількості студентів
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &n);

    Student students[MAX_STUDENTS];

    // Введення інформації про студентів
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d (Surname Group Web-Tech Ukr.language Project Design):\n", i + 1);
        scanf("%s %d %d %d %d", students[i].surname, &students[i].group, &students[i].web_tech, &students[i].ukr_language, &students[i].project_design);
    }

    // Виведення студентів із заборгованостями
    print_debtors(students, n);

    // Процент студентів, що здали всі екзамени на відмінно і добре
    double percentage = percentage_of_excellent_good_students(students, n);
    printf("Percentage of students who passed all exams with excellent and good grades: %.2f%%\n", percentage);

    // Найкраще зданий предмет
    const char* best_subj = best_subject(students, n);
    printf("Best performed subject: %s\n", best_subj);

    // Номер групи з найгіршою успішністю
    int worst_group = worst_performance_group(students, n);
    printf("Group number with the worst performance: %d\n", worst_group);

    return 0;
}
