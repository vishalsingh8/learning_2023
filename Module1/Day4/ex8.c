#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(char time[]) {
    char *token;
    unsigned long totalSeconds = 0;

    // Split the string using strtok
    token = strtok(time, ":");
    int hour = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    int minute = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    int second = strtoul(token, NULL, 10);

    // Compute total seconds
    totalSeconds = hour * 3600 + minute * 60 + second;

    return totalSeconds;
}

int main() {
    char time1[] = "12:12:50";
    unsigned long totalSeconds1 = computeTotalSeconds(time1);
    printf("Time: %s\n", time1);
    printf("Total seconds: %lu\n", totalSeconds1);

    char time2[] = "15:10:40";
    unsigned long totalSeconds2 = computeTotalSeconds(time2);
    printf("Time: %s\n", time2);
    printf("Total seconds: %lu\n", totalSeconds2);

    return 0;
}