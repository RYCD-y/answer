#ifdef _WIN32
#include <Windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <ncurses.h>
#endif

#include <stdio.h>
#include <time.h>

#include "database.h"

//登陆成功，进入系统
void enter(){
    printf("成功");

}

//输入密码
void input_password(Data *user_data, unsigned long long *password){
    printf("请输入您的姓名:");
    scanf("%s", user_data -> name);
    printf("请输入您的性别\033[90m(0代表女,1代表男):\033[0m");
    scanf("%d", &user_data -> sex);
    printf("请输入您的出生年份:");
    scanf("%d", &user_data -> birth_year);
    printf("请输入您的出生月份:");
    scanf("%d", &user_data -> birth_month);
    printf("请输入密码:");
    scanf("%lld", password);
}

//确认密码
_Bool confirm(Data user_data, unsigned long long *password) {
    char *sex = user_data.sex ? "男" : "女";
    while (1) {
        printf("\n请确认您的信息\n姓名:%s\n性别:%s\n出生年月:%d-%d\n密码:%lld\n\033[90m(按退格键返回修改，按回车键继续登录)\033[0m\n", user_data.name, sex, user_data.birth_year, user_data.birth_month, *password);
        char ch = 0;

#ifdef _WIN32

while(ch != 127 && ch != '\b' && ch != '\r' && ch != '\n'){
            ch = getch();
        }
#else
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE); 
            while(ch != 127 && ch != '/b' && ch != '/r' && ch != '/n'){
                ch = getch();
            }
#endif


        switch (ch) {
            case 127  :
            case '\b' :
                return 1;
            case '\r' :
            case '\n' :
                return 0;
        }
    }
}


//验证密码
_Bool verify(Data user_data, unsigned long long password){
    static short times_frozen = 0;
    for(short attempt = 2; ; attempt--){
        if(password == PASSWORD){
            for(int i = 0; i < MAX_ARRAY_SIZE; i++){
                if(strcmp(user_data.name, data[i].name) == 0){
                    if(user_data.sex == data[i].sex && user_data.birth_year == data[i].birth_year && user_data.birth_month == data[i].birth_month){
                        enter();
                        return 0;
                    }
                }
            }
        }
        if(attempt > 0){
            printf("信息错误, 您还剩余%d次机会\n\n", attempt);
            input_password(&user_data, &password);
        }else{
            //❤️惩❤️罚❤️环❤️节❤️
            attempt = 2;
            printf("请5分钟后再试\033[90m冻结次数%d\033[0m", times_frozen++);//测试为15s
#ifdef _WIN32
            Sleep(15000);//ms
#else
            sleep(15);//s
#endif

        }
    }
}

int main(){
    _Bool state_global = 1;
    _Bool state_input = 1;
    Data user_data;
    unsigned long long password;
    printf("信息录入系统登录\033[90m(按回车以前进)\033[0m\n");
    while(state_input){
        while(state_input){
            input_password(&user_data, &password);
            
            state_input = confirm(user_data, &password);
        }
        
        state_global = verify(user_data, password);
    }
    return 0;
}