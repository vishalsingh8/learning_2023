#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
};

void swapFields(struct Student *s1, struct Student *s2) {
    struct Student temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    struct Student student1, student2;

    printf("Enter details for student 1:\n");
    printf("Name: ");
    scanf(" %[^\n]", student1.name);
    printf("Roll Number: ");
    scanf("%d", &student1.rollNumber);

    printf("\nEnter details for student 2:\n");
    printf("Name: ");
    scanf(" %[^\n]", student2.name);
    printf("Roll Number: ");
    scanf("%d", &student2.rollNumber);

    printf("\nBefore swapping:\n");
    printf("Student 1:\n");
    printf("Name: %s\n", student1.name);
    printf("Roll Number: %d\n", student1.rollNumber);

    printf("\nStudent 2:\n");
    printf("Name: %s\n", student2.name);
    printf("Roll Number: %d\n", student2.rollNumber);

    // Swap the fields of the two structures
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1:\n");
    printf("Name: %s\n", student1.name);
    printf("Roll Number: %d\n", student1.rollNumber);

    printf("\nStudent 2:\n");
    printf("Name: %s\n", student2.name);
    printf("Roll Number: %d\n", student2.rollNumber);

    return 0;
}