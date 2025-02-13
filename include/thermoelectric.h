#ifndef THERMOELECTRIC_H
#define THERMOELECTRIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TE_MIN_TEMP 0
#define TE_MAX_TEMP 60
#define TE_ACCURACY 2.5
#define TE_DRIFT 0.6  

typedef struct {
    int id;
    char type[20];
    float last_value;
} ThermoelectricSensor;

void init_thermoelectric(ThermoelectricSensor *sensor, int id);
float get_thermoelectric_temp(ThermoelectricSensor *sensor, int years);

#endif
