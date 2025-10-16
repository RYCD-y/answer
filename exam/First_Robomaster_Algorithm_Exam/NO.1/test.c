#include "fibonacci.h"

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    fibonacci_sequence(n);
    printf("%d \n\n",fibonacci_nth(n));
    printf("%d \n\n",fibonacci_sum(n));

    return 0;
}
