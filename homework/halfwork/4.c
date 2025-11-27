/*
2/1 ,3/2, 5/3, 8/5, 13/8, 21/13，…求出这个数列前20个项的和

注意到，题式即为∑(F(n + 1) / Fn)(Fn为斐波那契数列，n >= 2)
记an = F(n + 1) / Fn， 则有an = 1 + 1 / an-1
*/

#include <stdio.h>

int main(){
    float sun = 0.0;
    float a[2] = {2.0, 1.0};
    for(int i = 0; i < 20; i++){
        sun += a[0] = 1.0f + 1.0f / a[1];
        a[1] = a[0];
    }
    printf("所求为：%f", sun);
    return 0;
}