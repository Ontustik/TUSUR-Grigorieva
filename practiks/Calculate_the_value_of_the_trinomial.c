#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int y(int a, int b, int c, int x)
{
	return a * (int)pow(x, 2) + b * x + c;
}

int main()
{
	int
		a = 0,
		b = 0,
		c = 0,
		x = 1;
	
	printf("A B C X\n");
	scanf("%d%d%d%d", &a, &b, &c, &x);
	printf("\n%d", y(a, b, c, x));
}
