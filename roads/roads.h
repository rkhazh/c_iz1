#ifndef ROADS_H
#define ROADS_H

#include <stdio.h>

#define SIZE 32

typedef enum roadtype {
    ASPHALT = 1, // 1 для того, чтобы считывать с консоли сразу тип дороги. Пользователь привык вести отсчет с единицы.
    PLASTIC,
    PAVED
} roadtype;

typedef struct Road { //typedef: struct Road -> Road
    int road_length;
    roadtype road_type;
    char from[SIZE];
    char to[SIZE];
    size_t number_of_lanes;
    int quality;
} Road;

double Roads_getAvgQuality(Road roads[], size_t size, roadtype type, size_t num_of_lanes); // [ClassName]_nameOfFunction; roads[] вместо Road* roads чтобы явно показать, что требуется массив

Road* getRoadsFromUser(FILE* stream, size_t* N);

int getSearchParams(FILE* stream, roadtype* road_t, size_t* numL);

#endif //ROADS_H
