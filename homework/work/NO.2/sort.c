
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

enum{
    SORT_DONE = 0,
    SORT_NOT_DONE
} sort_state;


// 生成随机数组
void generateArray(int arr[], int n){
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // 生成0~99的随机数
    }
}

// 打印数组
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) printf("%d ",arr[i]);
    printf("\n");
}
// 排序算法函数（至少实现两个，不局限于所给四种排序方式）

// 冒泡排序
void bubbleSort(int arr[], int n) {
    int a = 0;
    sort_state = SORT_NOT_DONE;
    while(sort_state == SORT_NOT_DONE){
        sort_state = SORT_DONE;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1]){
                sort_state = SORT_NOT_DONE;
                a = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = a;
            }
        }
    }
} 

// 选择排序 
void selectionSort(int arr[], int n){
    int a = 0;
    for(int i = 0; i < n; i++){
        for( int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]) {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }

        } 
    }
} 

// 插入排序
void insertionSort(int arr[], int n){
    int a = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0;j--){
            if(arr[j] < arr[j - 1]){
                a = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = a;
            }
        }
    }
} 

//被快速排序打爆了😭

int main()
{
    int n = 10;
    int arr[10] = {0};
    generateArray(arr, n);
    
    printArray(arr, n);


    bubbleSort(arr, n);
    printArray(arr, n);
    
    return 0;
}