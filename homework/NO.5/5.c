#include<stdio.h>

int power(int x,int y){
    if(y == 0 && x != 0)return 1;
    int r = x;
    while(y - 1 > 0){
        r *= x;
        y--;
    }
    return r;
}

int main(){
    int k = 0;
    for(int i = 100;i < 1000;i++){
        for(int j = 0;j < 3;j++){
            k += power((i / power(10,j)) % 10,3);
        }
        if(k == i){
            printf("%d\n",i);
        }else{
            k = 0;
        }
    }
    return 0;
}

//输出100~999的水仙花数