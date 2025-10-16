#include <stdio.h>
#include "fibonacci.h"

void fibonacci_sequence(int n){

    int a[3] = {0,1};
    for(int i = 0; i < n; i++){
        a[(i + 2) % 3] = a[(i + 1) % 3] + a[i % 3];//虽然效率不如置换，但是我觉得在数组里面转圈圈好帅😋
        printf("%d ",a[i % 3]);
        if(i % 8 == 7) printf("\n");
    }
    printf("\n\n");
}

long long fibonacci_nth(int n){
    int a[3] = {0,1};
    for(int i = 0; i < n; i++){
        a[(i + 2) % 3] = a[(i + 1) % 3] + a[i % 3];//同上
    }
    return a[(n - 1) % 3];
}

long long fibonacci_sum(int n){
    return fibonacci_nth(n + 2) - 1;//高中老师教的😎
}

