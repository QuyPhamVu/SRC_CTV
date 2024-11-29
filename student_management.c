#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CLASS_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char className[MAX_CLASS_LENGTH];
    int id;
    char username[MAX_NAME_LENGTH + 10];
} Student;

void createUsername(Student* student) {
    sprintf(student->username, "%s.%d", student->name, student->id);
}

void displayStudents(Student* students, int count) {
    printf("\n%-20s %-10s %-10s %-20s\n", "Name", "Class", "ID", "Username");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10s %-10d %-20s\n",
               students[i].name, students[i].className, students[i].id, students[i].username);
    }
}

    int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter information for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", students[i].name); 

        printf("Class: ");
        scanf("%s", students[i].className);

        printf("ID: ");
        scanf("%d", &students[i].id);

        createUsername(&students[i]);
    }

    displayStudents(students, n);

    free(students);

    return 0;
}
