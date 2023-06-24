#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to copy the file and handle the text case
void copyFileWithCaseHandling(FILE *source, FILE *destination, char option) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        if (option == 'u') {
            ch = toupper(ch);
        } else if (option == 'l') {
            ch = tolower(ch);
        } else if (option == 's') {
            if (islower(ch)) {
                ch = toupper(ch);
            }
        }
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments!\n");
        printf("Usage: %s <option> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char option = argv[1][0];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error creating destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFileWithCaseHandling(sourceFile, destinationFile, option);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
