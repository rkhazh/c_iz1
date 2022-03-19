#include "roads.h"
#include <malloc.h>


double Roads_getAvgQuality(Road roads[], size_t size, roadtype type, size_t num_of_lanes) { 
    if(roads == NULL || type > 3 || type < 1 || num_of_lanes == 0){
        return -1;
    }
    int count = 0;
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        if(roads[i].road_type == type && roads[i].number_of_lanes == num_of_lanes){
            sum += roads[i].quality;
            count++;
        }
    }
    //printf("%d", sum);
    return count != 0 ? (sum/count) : 0; 
}

void strIn(FILE* stream, char* const r) {
    do {
        printf("\n");
        if (stream == stdin) fscanf(stream, "%*[^\n]");
    } while (fscanf(stream, "%s", r) != 1);
}

void intIn(FILE* stream, int* const r) {
    do {
        printf("\n");
        if (stream == stdin) fscanf(stream, "%*[^\n]");
    } while (fscanf(stream, "%d", r) != 1);
}

void size_tIn(FILE* stream, size_t* const r) {
    do {
        printf("\n");
        if (stream == stdin) fscanf(stream, "%*[^\n]");
    } while (fscanf(stream, "%lu", r) != 1);
}

Road* getRoadsFromUser(FILE* stream, size_t* N){
    *N = 0;
    printf("Enter roads count:");
    {  // Использовал этот блок вместо процедуры intIn, чтобы не чистить буфер при первом чтении из потока. 
        size_t t = 0;
        do {
            t = fscanf(stream, "%lu", N);
            if((!!t) == 0 && stream == stdin){ // !!t -- для приведения t к логическому "типу" без подключения сторонних библиотек. В лекции было
                fscanf(stream, "%*[^\n]");
            }
        } while (t != 1 || *N == 0);
    }

    Road* roads = malloc(sizeof(Road) * (*N));
    if (roads == NULL){
        return NULL;
    }

    for (size_t i = 0; i < *N; i++) { //Ввод данных
        printf("Enter starting point:");
        strIn(stream, roads[i].from);
        printf("Enter destination:");
        strIn(stream, roads[i].to);
        printf("Enter road length:");
        intIn(stream, &(roads[i].road_length));
        printf("Enter road type:\n1 - ASPHALT\n2 - PLASTIC\n3 - PAVED");
        roads[i].road_type = 0; // На всякий случай инициализирую нулем.
        do { // Использую блок вместо процедуры intIn, чтобы прописать дополнительные проверки на road_type
            printf("\n");
            if (stream == stdin) fscanf(stream, "%*[^\n]"); // очикаст буфера
        } while (fscanf(stream, "%d", &(roads[i].road_type)) != 1 || roads[i].road_type < 1 || roads[i].road_type > 3);
        printf("Enter number of lanes:");
        size_tIn(stream, &(roads[i].number_of_lanes));
        printf("Enter quality:");
        intIn(stream, &(roads[i].quality));
    }
    return roads;
}

int getSearchParams(FILE* stream, roadtype* road_t, size_t* numL){
    printf("Enter road type to search:\n1 - ASPHALT\n2 - PLASTIC\n3 - PAVED");
    *road_t = 0;
    do { // Использую блок вместо процедуры intIn, чтобы прописать дополнительные проверки на road_type
        printf("\n");
        if (stream == stdin) fscanf(stream, "%*[^\n]"); // очистка буфера std in
    } while (fscanf(stream, "%d", road_t) != 1 || *road_t < 1 || *road_t > 3);
    printf("Enter number of lanes to search:");
    size_tIn(stream, numL);
    return 0;
} 
