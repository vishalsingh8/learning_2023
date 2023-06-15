#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    double pi = 3.14, e = 2.71;
    printf("Before swapping: pi = %.2f, e = %.2f\n", pi, e);
    swap(&pi, &e, sizeof(double));
    printf("After swapping: pi = %.2f, e = %.2f\n", pi, e);

    return 0;
}
