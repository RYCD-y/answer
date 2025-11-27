#include <stdio.h>
#include <math.h>

float y(float x){return 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;}

/**
 * @brief 二分法查找使得y = 0的x
 * 
 * 只能找出区间中的一个零点
 * 不满足y(a) * y(b) < 0则返回NaN
 *
 * @param 待查找函数的指针
 * @param 区间下界
 * @param 区间上界
 * @param 目标精度
 * @return 满足目标精度的x
 */
float Bisection(float (*y)(float), float a, float b, float pre){
    if(y(a) * y(b) < 0){
        while(fabs(a - b) > pre){
            if(y(a) * y((a + b) / 2) > 0){
                a = (a + b) / 2;
            }else if(y(a) * y((a + b) / 2) < 0){
                b = (a + b) / 2;
            }else{
                return (a + b) / 2;
            }
        }
        return (a + b) / 2;
    }else{
        return NAN;
    }
    
}

int main() {
    float x = Bisection(y, -10.0, 10.0, 1e-6);
    printf("%f", x);
    return 0;
}