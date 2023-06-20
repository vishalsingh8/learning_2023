#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Output: Original string
    printf("Original string: %s", str);

    // String conversion
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]);
    }

    // Output: Converted string
    printf("Converted string: %s", str);

    return 0;
}