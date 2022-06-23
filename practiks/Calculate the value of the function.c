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
	for (int x = -5; x <=5; x++)
	{
		printf("%5d \t-> %5d\n", x, f(x));
	}
}
