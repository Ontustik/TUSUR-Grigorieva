#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int
		row = 0,
		line = 0,
		id = 0;
	FILE*
		file = fopen("in.bin", "rb");
	FILE* file_out = fopen("out.txt", "w+");

	fread(&row, sizeof(int), 1, file);
	fread(&line, sizeof(int), 1, file);

	int** data = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i)
	{
		data[i] = (int*)malloc(sizeof(int)*line);
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			fread(&data[i][j], sizeof(int), 1, file);
		}
	}

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < line; ++j)
		{
			fprintf(file_out, "%d\t", data[i][j]);
			printf("%d\t", data[i][j]);
		}
		fprintf(file_out, "\n");
		printf("\n");
	}
	fprintf(file_out, "\n");
	printf("\n");

	for(int i = 0; i < row; ++i)
	{
		int
			count = 0;
		for(int j = 0; j < line; ++j)
		{
			if(data[i][j] < 0)
			{
				data[i][j] *= data[i][0];
				count++;
			}
		}
		if(count > 0)
		{
			fprintf(file_out, "Count[%d] = %d\n", i, count);
			printf("Count[%d] = %d\n", i, count);
			id++;
		}
	}
	printf("\n\n");
	fprintf(file_out, "\n\n");
	int row_id = row-1;

	if(id != row-1)
	{
		for(int i = 0; i < row; ++i)
		{
			for(int j = 0; j < line; j++)
			{
				if(data[i][j] < 0)
				{
					for(int q = 0; q < line; ++q)
					{
						int temp = data[i][q];
						data[i][q] = data[row_id][q];
						data[row_id][q] = temp;
					}
					i--;
					row_id--;
					break;
				}
			}
		}
	}
	else
	{
		printf("Все строки имеют отрицательный элемент");
		fprintf(file_out, "Все строки имеют отрицательный элемент");
	}


	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < line; ++j)
		{
			fprintf(file_out, "%d\t\t", data[i][j]);
			printf("%d\t\t", data[i][j]);
		}
		fprintf(file_out, "\n");
		printf("\n");
	}

}