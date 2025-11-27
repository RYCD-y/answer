#include <stdio.h>

int main() {
    int count = 0;
    for (int y1 = 0; y1 <= 25; y1++) {
        for (int y2 = 0; y2 <= 25 - y1; y2++) {
            for (int y3 = 0; y3 <= 25 - y1 - y2; y3++) {
                int y4 = 25 - y1 - y2 - y3;
                if (y4 >= 0) {
                    count++;
                }
            }
        }
    }
    printf("Total solutions: %d\n", count);
    return 0;
}