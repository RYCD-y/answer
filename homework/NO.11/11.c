#include<stdio.h>

int factorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * factorial(n - 1);
    }
}

int main(){
    for(int i = 0;i <= 9;i++) printf("%d! = %d\n",i,factorial(i));
}

//递归法求阶乘