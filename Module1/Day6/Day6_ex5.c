#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(const struct Student* students, int size, const char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found!\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
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

    char searchName[20];
    printf("Enter the name of the student to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove the newline character

    searchByName(students, size, searchName);

    free(students);
    return 0;
}