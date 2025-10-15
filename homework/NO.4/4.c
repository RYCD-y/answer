#include<stdio.h>

int main(){
    int a[3] = {1,1,0};
    for(int i = 0;i < 20;i++){
        a[(i + 2) % 3] = a[(i + 1) % 3] + a[i % 3];
        printf("%d\n",a[i % 3]);
    }
    return 0;
}

//数组方法输出斐波那契数列