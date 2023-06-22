#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

// Structure to store log entry information
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

// Function to extract each line in the .csv file and store it in an array of structures
int extractLogEntries(LogEntry logEntries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening data.csv\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int entryCount = 0;

    // Read each line in the file
    while (fgets(line, sizeof(line), file)) {
        
        char *token = strtok(line, ",");
        
        // Extract and store the log entry information
        logEntries[entryCount].entryNo = atoi(token);
        
        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].sensorNo, token, sizeof(logEntries[entryCount].sensorNo));
        logEntries[entryCount].sensorNo[sizeof(logEntries[entryCount].sensorNo) - 1] = '\0';
        
        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);
        
        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].timestamp, token, sizeof(logEntries[entryCount].timestamp));
        logEntries[entryCount].timestamp[sizeof(logEntries[entryCount].timestamp) - 1] = '\0';

        entryCount++;
    }

    fclose(file);
    return entryCount;
}

// Function to display the contents of the array of structures
void displayLogEntries(LogEntry logEntries[], int entryCount) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
               logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = extractLogEntries(logEntries);
    displayLogEntries(logEntries, entryCount);

    return 0;
}
