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
    EXPECT_EQ(Roads_GetQuality(roads,5,ASPHALT, 4), 13);
}
