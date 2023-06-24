#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Structure to hold the data
struct Data {
    int entryNo;
    char date[20];
    float temperature;
};

int main() {
    FILE* file = fopen("data.csv", "r+");
    
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    int targetEntryNo = 3;  // Entry number to update
    
    // Find the target entry
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);  // Skip the header line
    
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        struct Data data;
        sscanf(line, "%d,%[^,],%f", &data.entryNo, data.date, &data.temperature);
        
        if (data.entryNo == targetEntryNo) {
            // Update the entry
            float newTemperature = 25.5;  // New temperature value
            
            fseek(file, -(strlen(line)), SEEK_CUR);  // Move the file pointer back to the beginning of the line
            fprintf(file, "%d,%s,%.2f\n", data.entryNo, data.date, newTemperature);
            
            printf("Entry updated successfully.\n");
            break;
        }
    }
    
    fclose(file);
    
    return 0;
}
