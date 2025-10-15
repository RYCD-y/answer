#include <stdio.h>

int main(){
    float a = -1.0;
    char b[8];
    sprintf(b, "%f", a);
    printf("%s",b);
}