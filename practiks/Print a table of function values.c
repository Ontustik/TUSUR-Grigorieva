#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>

double f(int a, int n)
{
	double sum = 0;
	if(abs(a) <=1)
	{
		for (int i = 1; i <= n; i++)
		{
			sum+= (double)a/i;
		}
	}
	if(abs(a) > 1)
	{
		for(int i = 1; i <= n; i++)
		{
			sum += (double)a / pow(i, 2);
		}
	}
	return sum;
}

int main()
{
	char buffer[53];
	memset(buffer, '=', 52);
	buffer[52] = 0;

	printf("%s\n   a/n |%10d|%10d|%10d|%10d|\n%s", buffer, 5, 6, 7, 8, buffer);

	for (int a = -1; a <= 2; a++)
	{
		printf("\n|%5d ", a);
		for (int n = 5; n <=8; n++)
		{
			printf("|%10.3f", f(a, n));
		}
		printf("|");
	}
	printf("\n%s", buffer);

}
