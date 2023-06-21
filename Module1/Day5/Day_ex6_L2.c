#include <stdio.h>
#include <string.h>

struct SensorData {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char *data, struct SensorData *sensorArray) {
    char tempSensorID[10];
    float tempTemperature;
    int tempHumidity, tempLightIntensity;

    sscanf(data, "S%s-T:%f-H:%d-L:%d", tempSensorID, &tempTemperature, &tempHumidity, &tempLightIntensity);

    strcpy(sensorArray->sensorID, tempSensorID);
    sensorArray->temperature = tempTemperature;
    sensorArray->humidity = tempHumidity;
    sensorArray->lightIntensity = tempLightIntensity;
}

void printSensorInfo(const struct SensorData *sensorArray) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensorArray->sensorID);
    printf("Temperature: %.1f C\n", sensorArray->temperature);
    printf("Humidity: %d\n", sensorArray->humidity);
    printf("Light Intensity: %d%%\n", sensorArray->lightIntensity);
    printf("---------------------\n");
}

int main() {
    const char data[] = "S1-T:36.5-H:100-L:50";
    struct SensorData sensorArray;

    parseData(data, &sensorArray);
    printSensorInfo(&sensorArray);

    return 0;
}