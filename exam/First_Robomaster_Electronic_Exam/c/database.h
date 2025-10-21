#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdbool.h>

#define MAX_ARRAY_SIZE 255

typedef struct {
    char name[70];//留长一点照顾少数名族的朋友 
    _Bool sex;//0为女，1为男
    short birth_year;
    short birth_month;
    unsigned long long password;//19位数以内
} Data;

Data data[MAX_ARRAY_SIZE] = {
    {"小明", 1, 2019, 7, 123456},
    {"小红", 0, 2018, 5, 654321},
    {"小刚", 1, 2019, 8, 162534}
};//梦回小学

#endif