#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE* file = fopen("data.csv", "r");
    FILE* tempFile = fopen("temp.csv", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int targetEntryNo = 3; // Entry number to delete

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); // Read and write the header line to temp file
    fputs(line, tempFile);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int entryNo;
        sscanf(line, "%d", &entryNo); // Read the entry number from the line

        if (entryNo != targetEntryNo) {
            fputs(line, tempFile); // Write the line to temp file if the entry number is not the target
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temp file
    remove("data.csv");
    rename("temp.csv", "data.csv");

    printf("Entry deleted successfully.\n");

    return 0;
}
