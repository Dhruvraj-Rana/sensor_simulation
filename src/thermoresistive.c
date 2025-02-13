#include "../include/thermoresistive.h"
#include <stdio.h> 
#include <stdlib.h>

void init_thermoresistive(ThermoresistiveSensor *sensor, int id) {
    sensor->id = id;
    snprintf(sensor->type, 20, "Thermoresistive");
    sensor->last_value = 0.0;
}

float get_thermoresistive_temp(ThermoresistiveSensor *sensor, int years) {
    float base_temp = (rand() % (TR_MAX_TEMP - TR_MIN_TEMP + 1)) + TR_MIN_TEMP;
    float noise = ((rand() % 100) / 100.0) * TR_ACCURACY * ((rand() % 2) ? 1 : -1);
    float drift = (base_temp * TR_DRIFT * years) / 100;
    float temp = base_temp + noise + drift;

    if (temp < TR_MIN_TEMP) temp = TR_MIN_TEMP;
    if (temp > TR_MAX_TEMP) temp = TR_MAX_TEMP;

    sensor->last_value = temp;
    return temp;
}
