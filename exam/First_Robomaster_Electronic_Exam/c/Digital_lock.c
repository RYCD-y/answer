#include <stdio.h>
#include <string.h>
#include "database.h"

//登陆成功，进入系统
void enter(){
    //...
}

int main(){
    Data user_data;
    printf("信息录入系统的登录\033[90m(按回车以前进)\033[0m\n");
    printf("请输入您的姓名:");
    scanf("%s", user_data.name);
    printf("请输入您的性别\033[90m(0代表女,1代表男):\033[0m");
    scanf("%d", &user_data.sex);
    printf("请输入您的出生年份:");
    scanf("%d", &user_data.birth_year);
    printf("请输入您的出生月份:");
    scanf("%d", &user_data.birth_month);
    printf("请输入您的密码:");
    scanf("%lld", &user_data.password);

    char *sex = user_data.sex? "男": "女";

    printf("请确认您的信息\n姓名:%s\n性别:%s\n出生年月:%d-%d\n密码:%lld\n\033[90m(退格以退回输入密码环节, 按回车以尝试登录)\033[0m\n", user_data.name, sex, user_data.birth_year, user_data.birth_month, user_data.password);
    while(1){
        switch(getchar()){
            case '\b' :
                printf("请输入您的密码:");
                scanf("%d", &user_data.password);
                printf("请确认您的信息\n姓名:%s\n性别:%s\n出生年月:%d-%d\n密码:%lld\n\033[90m(退格以退回输入密码环节, 按回车以尝试登录)\033[0m\n", user_data.name, sex, user_data.birth_year, user_data.birth_month, user_data.password);
            case '\r' :
                break;
        }
    }

    for(int i = 0; i < MAX_ARRAY_SIZE; i++){
        if(strcmp(user_data.name, data[i].name) == 0){
            if(strcmp(&user_data, (data + i)) == 0){

            }
        }
    }

    return 0;
}