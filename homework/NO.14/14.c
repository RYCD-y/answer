#include<stdio.h>
#include<math.h>

int main(){
    for(int i = 6;i >= -6;i--){
        for(int j = -6;j <= 6;j++){
            if(4 * pow(j,2) + 4 * pow(i,2) - 5 * fabs(j) * i < 70.0){
                printf("# ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

//函数法输出爱心