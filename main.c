#include<stdio.h>
#include "mymath.h"
#include "math_if.h"
#include "stat.h"

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b = 5;
    int sum = calSum(a, b);
    int avg = calAvg(a, b);
    int c = sub(sum, avg);
    int d = mul(c, avg);
    printf("%d\n", c);
    printf("%d\n", avg);
    printf("%d\n", sum);
    printf("%d\n", d);
    return 0;
}