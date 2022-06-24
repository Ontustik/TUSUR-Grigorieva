/*
Дана целочисленная квадратная матрица.
1) Найти в каждой строке минимальный элемент.
2) Определить минимум среди модулей элементов главной диагонали;
3) Поменять сроку и столбец, находящиеся на пересечении этого элемента.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int** createMalloc(int size)
{
	int** array = (int**)malloc(sizeof(int*) * size);
	for(size_t i = 0; i < size; i++)
	{
		array[i] = (int*)malloc(sizeof(int)* size);
	}
	return array;
}

void fill(int** array, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand()%200-80;
		}
	}
}

void out(int** array, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}


int minStr(int** data, int size, int key)
{
	int min = data[key][0];
	for (size_t i = 1; i < size; i++)
	{
		if(min > data[key][i])
		{
			min = data[key][i];
		}
	}
	return min;
}

int minMod(int** data, int size)
{
	int min =abs(data[0][0]);
	int id = 0;
	for(size_t i = 1; i < size; i++)
	{
		if(min > abs(data[i][i]))
		{
			min = abs(data[i][i]);
			id = i;
		}
	}
	return id;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapData(int** array, int size, int i_) {
	for(size_t i = 0; i < size; i++)
	{
		swap(&array[i][i_], &array[i_][i]);
	}
}


int main()
{
	setlocale(LC_ALL, "RU");

	printf("Размер матрицы: ");
	int size = 0;
	scanf("%d", &size);
	//выделение память массиву
	int** data = createMalloc(size);
	//заполнение массива
	fill(data, size);

	printf("\n\nВывод матрицы: \n");
	out(data, size);

	//min
	printf("\n\nМинимальные элементы: \n");
	for (int i = 0; i < size; i++)
	{
		printf("Min[%d] - %d\n", i+1, minStr(data, size, i));
	}

	printf("\n\nМинимальный элемент по диагонали (модуль)\n");
	int id = minMod(data, size);
	printf("MinMod[%d] - %d\n",  id+1, data[id][id]);

	swapData(data, size, id);

	printf("\n\nВывод матрицы: \n");
	out(data, size);

}
