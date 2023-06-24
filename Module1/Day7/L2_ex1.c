#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Structure to hold the data
struct Data {
    char date[20];
    float temperature;
};

// Function to compare two data entries based on temperature
int compareData(const void* a, const void* b) {
    const struct Data* data1 = (const struct Data*)a;
    const struct Data* data2 = (const struct Data*)b;
    
    if (data1->temperature < data2->temperature) {
        return 1;  // Sort in descending order
    } else if (data1->temperature > data2->temperature) {
        return -1;
    }
    
    return 0;
}

int main() {
    FILE* file = fopen("data.csv", "r");
    
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    // Read the data from the file
    struct Data data[MAX_LINE_LENGTH];
    int numLines = 0;
    
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);  // Skip the header line
    
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* date = strtok(line, ",");
        char* temperatureStr = strtok(NULL, ",");
        
        strcpy(data[numLines].date, date);
        data[numLines].temperature = atof(temperatureStr);
        
        numLines++;
    }
    
    fclose(file);
    
    // Sort the data based on temperature
    qsort(data, numLines, sizeof(struct Data), compareData);
    
    // Write the sorted data to a new file
    FILE* outputFile = fopen("sorted_data.csv", "w");
    
    if (outputFile == NULL) {
        printf("Failed to create the output file.\n");
        return 1;
    }
    
    fprintf(outputFile, "Date,Temperature\n");  // Write the header line
    
    for (int i = 0; i < numLines; i++) {
        fprintf(outputFile, "%s,%.2f\n", data[i].date, data[i].temperature);
    }
    
    fclose(outputFile);
    
    printf("Data sorted successfully and written to 'sorted_data.csv'.\n");
    
    return 0;
}
