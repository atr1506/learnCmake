#include "mymath.h"
// #include "stat.h"

int calSum(int a[], int b)
{
	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		// sum += a[i];
        sum = add(a[i], sum);
	}
	return sum;
}

int calAvg(int a[], int b)
{
	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		sum += a[i];
        
	}
	return sum / b;
}