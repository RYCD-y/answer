#include<stdio.h>

int gcd(int a,int b){
    int c;
    if(a < b){
        c = b;
        b = a;
        a = c;
    }
    while(a % b != 0){
        a %= b;
        c = b;
        b = a;
        a = c;
    }
    return b;
}

int lcm(int a,int b){
    return (a * b) / gcd(a,b);
}

int main(){
    int a,b;
    printf("输入两个数字，计算最大公约数与最小公倍数");
    scanf("%d %d",&a,&b);
    printf("gcd = %d,lcm = %d",gcd(a,b),lcm(a,b));
    return 0;
}

//计算最大公约数与最小公倍数