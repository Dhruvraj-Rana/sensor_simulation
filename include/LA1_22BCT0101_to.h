#ifndef THERMO_OPTICAL_H
#define THERMO_OPTICAL_H

#define TO_MIN_TEMP 0
#define TO_MAX_TEMP 60
#define TO_ACCURACY 1.5
#define TO_DRIFT 0.6  

typedef struct {
    int id;
    char type[20];
    float last_value;
} ThermoOpticalSensor;

void init_thermo_optical(ThermoOpticalSensor *sensor, int id);
float get_thermo_optical_temp(ThermoOpticalSensor *sensor, int years);

#endif
