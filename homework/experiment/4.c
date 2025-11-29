/*
编写程序，实现如下功能：
1.	打印杨辉三角（仅打印N行，N为 6到10间的常数）
1  ---------------------------------------这是第1行
1  1   ---------------------------------这是第2行，依此类推
1  2  1
1  3  3   1
1  4  6   4   1
1  5  10  10  5  1
： ： ： ： ： ：
然后，对杨辉三角第12行的所有元素从大到小排序输出，并找出其中的质数。
质数（prime number）又称素数，定义为在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//冒泡排序
void sort(int *arr, size_t size){
    for(int i = size - 1; i > 0; i--){
        for(int j = 1; j <= i; j++){
            if(arr[j - 1] < arr[j]){
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < 12; i++){
        printf("%5d", arr[i]);
    }
}

//素性判断
_Bool is_prime(int num){
    if(num <= 1) return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    char n = 6;
    int yang[12][12] = {0};
    printf("请输入总行数(6~10)\n");
    scanf("%d", &n);
    while(n < 6 || 10 < n){
        printf("请输入属于6~10的整数\n");
        scanf("%d", &n);
    }

    //生成12层杨辉三角,并输出
    for(int i = 0; i < 12; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                yang[i][j] = 1;
            }else{
                yang[i][j] = yang[i - 1][j - 1] + yang[i - 1][j];
            }
            if(i < n){
                printf("%5d", yang[i][j]);
            }
        }
        printf("\n");
    }

    printf("杨辉三角的第十二行为:\n");
    sort(yang[11], sizeof(yang[11]) / sizeof(yang[11][0]));
    printf("\n其中");
    for(int i = 0; i < 12; i += 2){
        if(is_prime(yang[11][i])){
            printf("%d, ", yang[11][i]);
        }
    }
    printf("是素数");
    return 0;
}