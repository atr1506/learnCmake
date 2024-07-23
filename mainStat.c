#include<stdio.h>
#include "stat.h"

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b = 5;
    int avg = calAvg(a, b);
    printf("%d\n", avg);

    return 0;
}