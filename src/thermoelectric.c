#include "../include/LA1_22BCT0101_te.h"
#include <stdio.h>
#include <stdlib.h> 

void init_thermoelectric(ThermoelectricSensor *sensor, int id) {
    sensor->id = id;
    snprintf(sensor->type, 20, "Thermoelectric");
    sensor->last_value = 0.0;
}

float get_thermoelectric_temp(ThermoelectricSensor *sensor, int years) {
    float base_temp = (rand() % (TE_MAX_TEMP - TE_MIN_TEMP + 1)) + TE_MIN_TEMP;
    float noise = ((rand() % 100) / 100.0) * TE_ACCURACY * ((rand() % 2) ? 1 : -1);
    float drift = (base_temp * TE_DRIFT * years) / 100;
    float temp = base_temp + noise + drift;

    if (temp < TE_MIN_TEMP) temp = TE_MIN_TEMP;
    if (temp > TE_MAX_TEMP) temp = TE_MAX_TEMP;

    sensor->last_value = temp;
    return temp;
}
