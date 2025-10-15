#include<stdio.h>

int main()
{
    //1234
    for(int i = 1;i < 5;i++){
        for(int j = 1;j < 5;j++){
            for(int k = 1;k < 5;k++){
                if(i != j && j != k && k != i){
                    printf("%d,%d,%d \n",i,j,k);
                }
            }
        }
    }
}

//输出1234排出的不重复的所有三位数
//这是一个修改
//又修改
//
//你好