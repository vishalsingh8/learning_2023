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

    int sumOdd = 0;
    int sumEven = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } else {
            sumOdd += arr[i];
        }
    }

    int difference = sumOdd - sumEven;

    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Sum of even elements: %d\n", sumEven);
    printf("Difference: %d\n", difference);

    return 0;
}