#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float average;

    // Calculate the sum
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Calculate the average
    average = (float) sum / size;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}