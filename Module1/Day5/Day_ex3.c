#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void differenceBetweenTimePeriod(struct Time start, struct Time end, struct Time *diff) {
    if (end.seconds > start.seconds) {
        --start.minutes;
        start.seconds += 60;
    }

    diff->seconds = start.seconds - end.seconds;

    if (end.minutes > start.minutes) {
        --start.hours;
        start.minutes += 60;
    }

    diff->minutes = start.minutes - end.minutes;
    diff->hours = start.hours - end.hours;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    printf("\nEnter the end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    differenceBetweenTimePeriod(startTime, endTime, &difference);

    printf("\nTime difference: %d hours, %d minutes, %d seconds.\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}