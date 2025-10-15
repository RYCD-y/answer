#include<stdio.h>

int main(){
    int a;
    printf("输入数字分解因数\n");
    scanf("%d",&a);
    printf("=");
    for(int i = 2;i < a;i++){
        if(a % i == 0){
            printf("%d * ",i);
            a /= i;
            i = 2;
        }
    }
    printf("%d",a);
    return 0;
}

//质因数分解