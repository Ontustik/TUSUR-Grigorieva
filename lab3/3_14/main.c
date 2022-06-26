#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int
		row = 0,
		line = 0;

	printf("Row - ");
	scanf("%d", &row);

	printf("\nLine - ");
	scanf("%d", &line);
    printf("\n");
	FILE*
		file = fopen("in.bin", "wb+");

	fwrite(&row, sizeof(int), 1, file);
	fwrite(&line, sizeof(int), 1, file);
	srand(time(NULL));
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < line; ++j)
		{
			int num = rand() % 200 - 40;
			fwrite(&num, sizeof (int), 1, file);
            printf("%d\t", num);
		}
        printf("\n");
	}
}