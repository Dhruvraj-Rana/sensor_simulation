#include "../include/thermo_optical.h"
#include <stdio.h>  // Fix snprintf error
#include <stdlib.h> // Fix rand error

void init_thermo_optical(ThermoOpticalSensor *sensor, int id) {
    sensor->id = id;
    snprintf(sensor->type, 20, "Thermo-Optical");
    sensor->last_value = 0.0;
}

float get_thermo_optical_temp(ThermoOpticalSensor *sensor, int years) {
    float base_temp = (rand() % (TO_MAX_TEMP - TO_MIN_TEMP + 1)) + TO_MIN_TEMP;
    float noise = ((rand() % 100) / 100.0) * TO_ACCURACY * ((rand() % 2) ? 1 : -1);
    float drift = (base_temp * TO_DRIFT * years) / 100;
    float temp = base_temp + noise + drift;

    if (temp < TO_MIN_TEMP) temp = TO_MIN_TEMP;
    if (temp > TO_MAX_TEMP) temp = TO_MAX_TEMP;

    sensor->last_value = temp;
    return temp;
}
