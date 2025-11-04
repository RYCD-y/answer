#include <stdio.h>
#include <string.h>
#include <math.h>

#define G 0.98
#define R 1.0
#define K 1.0


int main(){
    float dT = 0.01;
    

    float Kp = 5.0;
    float Ki = 0.0;
    float Kd = 2.0;
    
    float u = 0.0;
    float du = 0.0;

    float pitch = 50.0;

    float v = 0;
    
    float e[3] = {0.0, 0.0, 0.0};
    
    for(int i = 0; !(fabsf(du) < 1e-6 && fabsf(pitch) < 1e-6) && i < 1000; i++){
        

        e[2] = e[1];
        e[1] = e[0];
        e[0] = 90 - pitch;
        du = Kp * (e[0] - e[1]) + Ki * e[0] + Kd * (e[0] - 2 * e[1] + e[2]);
        u += du;

        v += ((K * u * sin(pitch / 57.2958)) - (G * cos(pitch / 57.2958))) * dT;
        // v0 += K * u * sin(pitch) * dT;
        pitch += (v * dT) /  R;
        
        //printf("%f\n", pitch);
        for(int i = 0; i < pitch / 10; i++) printf("▮");
        printf("\n");
        
    }
    

    return 0;
}