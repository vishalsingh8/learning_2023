#include <stdio.h>

void printBits(int num) {
    int i;
    int mask = 1 << 31;  // Start with the leftmost bit

    for (i = 0; i < 32; i++) {
        // Check if the current bit is set or not
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }

        // Shift the mask to the right to check the next bit
        mask = mask >> 1;
    }

    printf("\n");
}

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
