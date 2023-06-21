#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayArray(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
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

    // Assume the array of structures is already initialized with values

    displayArray(students, size);

    free(students);
    return 0;
}