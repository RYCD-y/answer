#include <stdio.h>

int Prime_number_testing(int n){
    if(n == 1) return 0;

    for(int i = 2; i * i < n; i++) if(n % i == 0) return 0;
    return 1;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    if(Prime_number_testing(n)){
        printf("%d是素数", n);
    }else{
        printf("%d不是素数", n);
    }
    return 0;
}

//暴力方法判断素数