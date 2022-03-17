#include <stdio.h>
#include <malloc.h>
#include "roads.h"

void stdIn_str(char r[]){
    size_t t = 0;
    do{
        printf("\n");
        scanf("%*[^\n]");
        t = scanf("%s", r);
    } while(t!=1);
}
void stdIn_int(int* r){
    size_t t = 0;
    do{
        printf("\n");
        scanf("%*[^\n]");
        t = scanf("%d", r);
    } while(t!=1);
}

//Макрос для перегрузки процедуры
#define stdIn(X)          \
    _Generic((X),         \
    int*: stdIn_int,      \
    char*: stdIn_str,     \
    default: stdIn_int    \
)(X)

int main() {
    printf("Hello, World!\n" );
    int N = 0;
    printf("Enter roads count:");
    {
        size_t t = 0;
        do {
            t = scanf("%d", &N);
            if((!!t) == 0){
                scanf("%*[^\n]");
            }
        } while (t != 1 || N <= 0);
    }
    Road* roads = malloc(sizeof(Road) * N);
    for(size_t i = 0; i < N; i++) { //Ввод данных
        printf("Enter starting point:");
        stdIn(roads[i].from);
        printf("Enter destination:");
        stdIn(roads[i].to);
        printf("Enter road length:");
        stdIn(&(roads[i].road_length));
        printf("Enter road type:\n1 - ASPHALT\n2 - PLASTIC\n3 - RUBBLE");
        stdIn_int(&(roads[i].road_type));
        printf("Enter number of lanes:");
        stdIn(&(roads[i].number_of_lanes));
        printf("Enter quality:");
        stdIn(&(roads[i].quality));
    }
    printf("%f",Roads_GetQuality(roads, N, ASPHALT, 4));
    return 0;
}
