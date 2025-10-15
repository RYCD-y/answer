#include<stdio.h>

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int main(){
    for(int i = -4; i <= 4;i++){
        for(int j = -4;j <= 4;j++){
            if(abs(i) + abs(j) - 4 < 0){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

//函数法输出菱形