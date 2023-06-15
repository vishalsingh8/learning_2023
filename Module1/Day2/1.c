#include <stdio.h>
#include <stdint.h>

void printExponent(double num) {
    uint64_t* bits = (uint64_t*)(&num);
    uint64_t exponent = ((*bits) >> 52) & 0x7FF;

    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    
    printf("Exponent in binary: 0b");
    for (int i = 10; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
