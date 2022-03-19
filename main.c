#include <stdio.h>
#include "roads.h"
#include <stdlib.h>
#include <string.h>


int main() {
    Road* road_map;
    size_t N = 0;
    road_map = getRoadsFromUser(stdin, &N);
    if (road_map == NULL) {
        return -1;
    }

    size_t n_lanes_to_search = 0;
    roadtype type_to_search = 0;
    if (getSearchParams(stdin, &type_to_search, &n_lanes_to_search)) {
        free(road_map);
        return -1;
    }

    double res = Roads_getAvgQuality(road_map, N, type_to_search, n_lanes_to_search);
    if (res == -1){
        free(road_map);
        return -1;
    }
    printf("Average quality: %lf", res);

    free(road_map);
    return 0;
}
