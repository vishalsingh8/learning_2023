#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compare(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    } else {
        return 0;
    }
}

void sortArray(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compare);
}

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

    // Populate the array with student details
    for (int i = 0; i < size; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        getchar();  // Ignore the newline character

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove the newline character

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar();  // Ignore the newline character
    }

    sortArray(students, size);

    printf("\nSorted Array:\n");
    displayArray(students, size);

    free(students);
    return 0;
}