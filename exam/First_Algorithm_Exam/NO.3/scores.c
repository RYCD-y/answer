#include <stdio.h>
#include <string.h>

/*
  输入学生成绩
  scores 指向成绩数组的指针
  n 学生人数
 */
void inputScores(int *scores, int n){
    for(int i = 0; i < n; i++){
        scanf("%d",scores + i);
    }
}

/*
 计算平均分
 scores 指向成绩数组的指针
 n 学生人数
 return 平均分
 */
double calculateAverage(int *scores, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(scores + i);
    }
    return sum / (double)n;
}

/*
 查找最高分和最低分
 scores 指向成绩数组的指针
 n 学生人数
 max 指向存储最高分的变量的指针
 min 指向存储最低分的变量的指针
 */
void findMinMax(int *scores, int n, int *max, int *min){
    *max = *scores;
    *min = *scores;
    for(int i = 0; i < n; i++){
        if(*max < *(scores + i)){
            *max = *(scores + i);
        }
        if(*min > *(scores + i)){
            *min = *(scores + i);
        }  
    }
}

enum{
    SORT_DONE = 0,
    SORT_NOT_DONE
} sort_state;

/*
 对成绩进行降序排序
 scores 指向成绩数组的指针
 n 学生人数
 */
void sortScores(int *scores, int n){
    int a = 0;
    sort_state = SORT_NOT_DONE;
    while(sort_state == SORT_NOT_DONE){
        sort_state = SORT_DONE;
        for(int i = 0; i < n - 1; i++){
            if (*(scores + i) < *(scores + i + 1)){
                sort_state = SORT_NOT_DONE;
                a = *(scores + i);
                *(scores + i) = *(scores + i + 1);
                *(scores + i + 1) = a;
            }
        }
    }
}// 冒泡排序,从第二题抄的😜

/*
 统计各等级人数
 scores 指向成绩数组的指针
 n 学生人数
 counts 指向等级统计数组的指针
 counts[0]: 优秀人数(90-100)
 counts[1]: 良好人数(80-89)
 counts[2]: 中等人数(70-79)
 counts[3]: 及格人数(60-69)
 counts[4]: 不及格人数(0-59)
 */
void countGrades(int *scores, int n, int *counts) {
    // 初始化统计数组
        memset(counts, 0, 5 * sizeof(int));
    //遍历
    for (int i = 0; i < n; i++) {
        int score = scores[i];
        
        if (score >= 90) {
            counts[0]++;  // 优秀
        } else if (score >= 80) {
            counts[1]++;  // 良好
        } else if (score >= 70) {
            counts[2]++;  // 中等
        } else if (score >= 60) {
            counts[3]++;  // 及格
        } else {
            counts[4]++;  // 不及格
        }
    }
}



int main() {
    int numStudents;
    
    printf("请输入学生人数: ");
    scanf("%d", &numStudents);
    
    int scores[numStudents];
    int gradeCounts[5] = {0};
    
    // 调用各功能函数
    inputScores(scores, numStudents);
    
    double avg = calculateAverage(scores, numStudents);
    printf("平均分: %.2f\n", avg);
    
    int maxScore, minScore;
    findMinMax(scores, numStudents, &maxScore, &minScore);
    printf("最高分: %d, 最低分: %d\n", maxScore, minScore);
    
    sortScores(scores, numStudents);
    printf("成绩降序排列: ");
    for(int i = 0; i < numStudents; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    
    countGrades(scores, numStudents, gradeCounts);
    printf("等级统计:\n");
    printf("优秀(90-100): %d人\n", gradeCounts[0]);
    printf("良好(80-89): %d人\n", gradeCounts[1]);
    printf("中等(70-79): %d人\n", gradeCounts[2]);
    printf("及格(60-69): %d人\n", gradeCounts[3]);
    printf("不及格(0-59): %d人\n", gradeCounts[4]);
    
    return 0;
}