#include <stdio.h>
#define PI 3.1415926

int main() {
    int a, b;
    int hundreds, tens, units;
    float area;

    printf("请输入一个三位数：");
    scanf("%d", &a);

    hundreds = a / 100;
    tens = (a / 10) % 10;
    units = a % 10;

    printf("百位数：%d\n", hundreds);
    printf("十位数：%d\n", tens);
    printf("个位数：%d\n", units);

    b = units * 100 + tens * 10 + hundreds;
    printf("反序后的数字为：%d\n", b);

    int outer = a > b ? a : b;
    int inner = a < b ? a : b;
    area = PI * (outer * outer - inner * inner);

    printf("圆环的面积为：%.2f\n", area);

    return 0;
}