#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student* students, int size, const char* inputString) {
    char rollnoStr[20], name[20], marksStr[20];
    sscanf(inputString, "%s %s %s", rollnoStr, name, marksStr);

    for (int i = 0; i < size; i++) {
        students[i].rollno = atoi(rollnoStr);
        strncpy(students[i].name, name, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        students[i].marks = atof(marksStr);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Ignore the newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char inputString[100];
    printf("Enter the student details in the format 'rollno name marks':\n");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';  // Remove the newline character

    initializeArray(students, size, inputString);

    // Test printing the initialized array
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);
    return 0;
}