#include<stdio.h>

//60  90

int main(){
    int grade;
    int i;
    char eva[] ={'A','B','C'};
    printf("输入分数评级");
    scanf("%d",&grade);
    i = (grade >= 90) ? 0 : (grade >= 60 ? 1 : 2);
    printf("%c",eva[i]);
}

//?:代替if