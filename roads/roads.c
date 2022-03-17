#include <stdio.h>
#include "roads.h"

double Roads_GetQuality (Road roads[], size_t size, ROADTYPE type, int num_of_lanes) {
    int c = 0;
    double Sum = 0;
    for(int i = 0; i < size; i++){
        if(roads[i].road_type == type && roads[i].number_of_lanes == num_of_lanes){
            Sum += roads[i].quality;    
            c++;
        }
    }
    return c!=0 ? (Sum/c) : 0;
}