#ifndef THERMO_ACOUSTIC_H
#define THERMO_ACOUSTIC_H

#define TA_MIN_TEMP 0
#define TA_MAX_TEMP 60
#define TA_ACCURACY 2.0
#define TA_DRIFT 0.6  

typedef struct {
    int id;
    char type[20];
    float last_value;
} ThermoAcousticSensor;

void init_thermo_acoustic(ThermoAcousticSensor *sensor, int id);
float get_thermo_acoustic_temp(ThermoAcousticSensor *sensor, int years);

#endif
