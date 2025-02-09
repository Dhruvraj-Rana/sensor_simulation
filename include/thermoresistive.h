#ifndef THERMORESISTIVE_H
#define THERMORESISTIVE_H

#define TR_MIN_TEMP 0
#define TR_MAX_TEMP 60
#define TR_ACCURACY 1.0
#define TR_DRIFT 0.6  

typedef struct {
    int id;
    char type[20];
    float last_value;
} ThermoresistiveSensor;

void init_thermoresistive(ThermoresistiveSensor *sensor, int id);
float get_thermoresistive_temp(ThermoresistiveSensor *sensor, int years);

#endif
