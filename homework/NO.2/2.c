#include <stdio.h>
//能被4整除而不能被100整除的、能被400整除的年份都是闰年
int isLeapYear(int year){
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        return 1;
    }
    return 0;
}

void main(){
    int year,month,day;
    int d = 0;
    int dayinmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("输入年份");
    scanf("%d %d %d",&year,&month,&day);

    for(int i= 0;i < month - 1;i++){
        d += dayinmonth[i];
    }
    d += day;
    if(month > 2 && isLeapYear(year) == 1)d++;
        printf("%d年%d月%d日是那一年的第%d天",year,month,day,d);
}

//判断yy mm dd是当年的第几天
