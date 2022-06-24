/*
Дана вещественная квадратная матрица.
1)	 Определить номер строки, в которой расположен максимальный элемент второго столбца массива. Если элементов с максимальным значением в этом столбце несколько, то должен быть найден номер строки самого верхнего из них;
2)	Определить координаты первого максимального элемента главной 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double fRand()
{
	double f = (double)rand() / RAND_MAX;
	return -100 + f * (100 - (-100));
}

void out(double** arr, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			printf("%.2lf\t", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int size = 0;
	srand(time(NULL));
	printf("Size - ");
	scanf("%d", &size);

	//Выделение памяти через malloc
	double** arr = (double**)malloc(sizeof(double*)*size);
	for (int i = 0; i < size; ++i)
	{
		arr[i] = (double*)malloc(sizeof(double)*size);
	}

	// Заполнение массива вещественными числами
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			arr[i][j] = fRand();
		}
	}

	out(arr, size);
	

	int id = 0;
	for (int i = 0; i < size; ++i)
	{
		if(arr[1][id] <= arr[1][i])
		{
			id = i;
		}
	}
	printf("MAX[1][%d]  = %lf\n", id, arr[1][id]);

	id = 0;
	for (int i = 0; i < size; ++i)
	{
		if(arr[i][id] > arr[i][i])
		{
			id = i;
		}
	}
	printf("MAX[%d][%d]  = %lf\n", id, id, arr[1][id]);

	id = 0;
	printf("k - ");
	scanf("%d", &id);

	for (int i = 0; i < size; i++)
	{
		double temp = arr[0][i];
		arr[0][i] = arr[id][i];
		arr[id][i] = temp;
	}

	out(arr, size);

}
