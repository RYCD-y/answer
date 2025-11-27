#include <stdio.h>

int main(){
    char str[256] = "", 
         word = 0;
    fgets(str, sizeof(str), stdin);

    for(int i = 0; i < 255; i++){
        if(str[i] != '\0'){
            if(str[i] != ' '){
                printf("%c", str[i]);
                if(str[i + 1] == ' ' || str[i + 1] == '\0'){
                    printf("\n");
                    word++;
                }
            }
        }else{
            break;
        }
    }
    printf("共%d个单词\n", word);

    return 0;
}