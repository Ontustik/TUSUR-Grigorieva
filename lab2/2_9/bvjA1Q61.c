#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int count(int** data, int line, int i) {
	int count = 0;
	for(int j = 0; j < line; j++) {
		count += data[i][j];
	}
	return count;
}

void out(int** arr, int row, int line, FILE* file)
{
	for(int i = 0; i < row; ++i)
	{
		printf("[%d]\t\t", i + 1);
		fprintf(file, "[%d]\t\t", i + 1);
		for(int j = 0; j < line; ++j)
		{
			printf("%d\t", arr[i][j]);
			fprintf(file, "%d\t", arr[i][j]);
		}
		fprintf(file, "\n");
		printf("\n");
	}
}

int main()
{
	srand(time(NULL));
	int
		row = 0,
		line = 0;

	FILE* file = fopen("in.txt", "r");
	FILE* file_out = fopen("out.txt", "w");

	fscanf(file, "%d%d", &row, &line);
	fprintf(file_out, "ROW - %d\nLINE = %d\n", row, line);
	printf("ROW - %d\nLINE = %d\n", row, line);

	int** arr = (int**)malloc(sizeof(int*) * row);
	for(int i = 0; i < row; ++i)
	{
		arr[i] = (int*)malloc(sizeof(int) * line);
	}

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < line; ++j)
		{
			fscanf(file, "%d ", &arr[i][j]);
		}
	}

	out(arr, row, line, file_out);

	int
		max = 0,
		id = 0;

	for(int i = 0; i < row; ++i)
	{
		int temp = count(arr, line, i);
		if(temp > max)
		{
			id = i;
			max = temp;
		}
	}

	int save_id = id;

	printf("\nMAX[%d]", id);
	fprintf(file_out, "\nMAX[%d]", id);
	id = 0;
	printf("\nStudents in the k course[1-4]: ");

	scanf("%d", &id);

	printf("\nCount[%d] = %d\n", id, count(arr, line, id - 1));
	fprintf(file_out, "\nCount[%d] = %d\n", id, count(arr, line, id - 1));
	id = 0;

	for(int i = 0; i < row; ++i)
	{
		if(count(arr, line, save_id > count(arr, line, i)))
		{
			id = save_id = i;
		}
	}

	for(int i = 0; i < line; ++i)
	{
		arr[id][i] = 0;
	}


	out(arr, row, line, file_out);
}