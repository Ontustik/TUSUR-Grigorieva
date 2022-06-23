#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int x)
{
	if(x < 0)
	{
		return x * x + 7;
	}
	else if(x > 0)
	{
		return x * x * x + 9;
	}
	else
	{
		return 0;
	}
}

int main()
{
	printf("%d\n", f(-5));
	printf("%d\n", f(5));
	printf("%d\n", f(0));
}
