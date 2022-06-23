#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//WARNING!!!!!!!
	// There is no clear condition, the problem may not be solved correctly
	//
	const int a = -5;
	const int b = 0;
	const int c = 5;
	const int d = 10;

	int x = 0, y = 0;
	scanf("%d%d", &x, &y);

	int counter = 0;
	for (int i = x; i <=y; i++)
	{
		if(i >= a && i <= d)
		{
			if(i >= b&& i <= d)
			{
				if(i >=c && i <= d)
				{
					counter++;
				}
			}
		}
	}
	printf("\n%d", counter);
}
