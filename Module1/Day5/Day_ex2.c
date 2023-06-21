#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex readComplexNumber() {
    struct Complex c;

    printf("Enter real part: ");
    scanf("%f", &c.real);

    printf("Enter imaginary part: ");
    scanf("%f", &c.imag);

    return c;
}

void writeComplexNumber(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

struct Complex addComplexNumbers(struct Complex c1, struct Complex c2) {
    struct Complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;

    return result;
}

struct Complex multiplyComplexNumbers(struct Complex c1, struct Complex c2) {
    struct Complex result;

    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;

    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter first complex number:\n");
    num1 = readComplexNumber();

    printf("\nEnter second complex number:\n");
    num2 = readComplexNumber();

    printf("\nFirst complex number:\n");
    writeComplexNumber(num1);

    printf("\nSecond complex number:\n");
    writeComplexNumber(num2);

    // Addition of two complex numbers
    sum = addComplexNumbers(num1, num2);
    printf("\nSum of the two complex numbers:\n");
    writeComplexNumber(sum);

    // Multiplication of two complex numbers
    product = multiplyComplexNumbers(num1, num2);
    printf("\nProduct of the two complex numbers:\n");
    writeComplexNumber(product);

    return 0;
}