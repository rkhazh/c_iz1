
#ifndef ROADS_H
#define ROADS_H
typedef enum ROADTYPE{
    ASPHALT = 1, PLASTIC, RUBBLE
} ROADTYPE;

typedef struct Road{
    int road_length;
    ROADTYPE road_type;
    char from[32];
    char to[32];
    int number_of_lanes;
    int quality;
} Road;

double Roads_GetQuality (Road roads[], size_t size, ROADTYPE type, int num_of_lanes);
#endif //ROADS_H
