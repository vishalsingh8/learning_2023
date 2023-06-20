#include <stdio.h>

int stringToInteger(char str[]) {
    int res = 0;
    int i = 0;

    // Handle negative numbers
    if (str[0] == '-') {
        i = 1;
    }

    // Iterate through each character of the string
    while (str[i] != '\0') {
        // Convert character to integer
        int ival = str[i] - '0';

        // Accumulate the value
        res = res * 10 + ival;

        i++;
    }

    // Handle negative numbers
    if (str[0] == '-') {
        res = -res;
    }

    return res;
}

int main() {
    char str[] = "448578";

    // Convert string to integer
    int value = stringToInteger(str);

    // Output
    printf("String: %s\n", str);
    printf("Integer: %d\n", value);

    return 0;
}