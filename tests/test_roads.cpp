#include <gtest/gtest.h>

extern "C" {
    #include "roads.h"
}

TEST(Roads, TestGetQuality) {
    Road roads[5] = {
        {1000, ASPHALT, "from", "to", 4, 10},
        {1200, PLASTIC, "from", "to", 4, 20},
        {900, ASPHALT, "from", "to", 5, 9},
        {200, ASPHALT, "from", "to", 4, 15},
        {1000, ASPHALT, "from", "to", 4, 14},
    };
    EXPECT_EQ(Roads_getAvgQuality(roads,5,ASPHALT, 4), 13);
}

/*
// Выдает segmentation fault. В gdb указано,
что броблема в size_tIn, но я так и не смог разобраться
TEST(Roads, getSearchParamsTest){ 
    char buffer[] = "1 4";
    FILE *stream;
    stream = fmemopen(buffer, strlen (buffer), "r");
    roadtype* road_t;
    size_t* numL;
    getSearchParams(stream, road_t, numL);
    if(road_t == NULL) exit(1);
    free(stream);
    //assert(*road_t == PLASTIC);
    //assert(*numL == 3);
}
*/

TEST(RADS, TestAllIsOne){
    Road roads[2] = {
        {1, ASPHALT, "1", "1", 1, 1},
        {1, ASPHALT, "1", "1", 1, 1}
    };
    EXPECT_EQ(Roads_getAvgQuality(roads,2,ASPHALT, 1), 1);
}

TEST(Roads, getRoadsFromUserTest){
    char buffer[] = "1 From To 13 1 4 20";
    FILE *stream;
    stream = fmemopen(buffer, strlen (buffer), "r");
    size_t* N;
    if(stream == NULL) { exit(1);}
    Road* roads = getRoadsFromUser(stream, N);
    if(roads == NULL) { exit(1);}
    free(roads);
    free(stream);
}
