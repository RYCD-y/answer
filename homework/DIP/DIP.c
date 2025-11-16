#include <stdio.h>
#include <string.h>
#include <math.h>

#define G 0.98
#define R 1.0
#define K 1.0

//返回
short PID(float Kp, float Ki,float Kd,float error){
    static float e[3] = {0};
    static float u = 0.0;

    e[2] = e[1];
    e[1] = e[0];
    e[0] = error;

    u += (Kp + Ki + Kd) * e[0] - (Kp + 2 * Kd) * e[1] + Kd * e[2];

    return (short)u;
}

int main(){
    return 0;
}