#include "../include/LA1_22BCT0101_ta.h"
#include <stdio.h>  
#include <stdlib.h>

void init_thermo_acoustic(ThermoAcousticSensor *sensor, int id) {
    sensor->id = id;
    snprintf(sensor->type, 20, "Thermo-Acoustic");
    sensor->last_value = 0.0;
}

float get_thermo_acoustic_temp(ThermoAcousticSensor *sensor, int years) {
    float base_temp = (rand() % (TA_MAX_TEMP - TA_MIN_TEMP + 1)) + TA_MIN_TEMP;
    float noise = ((rand() % 100) / 100.0) * TA_ACCURACY * ((rand() % 2) ? 1 : -1);
    float drift = (base_temp * TA_DRIFT * years) / 100;
    float temp = base_temp + noise + drift;

    if (temp < TA_MIN_TEMP) temp = TA_MIN_TEMP;
    if (temp > TA_MAX_TEMP) temp = TA_MAX_TEMP;

    sensor->last_value = temp;
    return temp;
}
