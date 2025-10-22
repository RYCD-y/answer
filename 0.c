#include <stdio.h>

void read_input() {
    printf("请输入内容（按退格键测试，按回车键结束）：\n");
    int input_length = 0; // 记录当前行的输入长度
    while (1) {
        int ch = getchar(); // 捕获用户输入

        if (ch == '\n') {
            printf("检测到回车键，结束输入。\n");
            break;
        } else if (ch == '\b' || ch == 127) { // 检测退格键
            if (input_length > 0) {
                input_length--; // 删除一个字符
                printf("检测到退格键，删除一个字符。\n");
            } else {
                printf("检测到退格键，但已在行首。\n");
            }

        } else {
            input_length++; // 增加输入长度
            printf("检测到字符：%c\n", ch);
        }
    }
}

int main() {
    read_input();
    return 0;
}