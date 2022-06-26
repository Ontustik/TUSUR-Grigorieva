#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct WORKER
{
	char FCs[50];
	char office[50];
	char post[50];
	unsigned int payroll;
};

void out(struct WORKER data)
{

	printf("%*s", 30, data.FCs);
	printf("%*s", 20, data.office);
	printf("%*s", 20, data.post);
	printf("%*d\n", 15, data.payroll);
}

void out_to_table(struct WORKER* data, int size1, FILE* file)
{
	//Формируем полосы из '-'
	char buffer[114];
	memset(buffer, '-', 113);
	buffer[113] = 0;

	// Название Таблицы
	fprintf(file, "+%s+\n|", buffer);
	fprintf(file, "%*s\n", 65, "WORKER");
	fprintf(file, "+%s+\n", buffer);
	// Заголовоки колонки
	fprintf(file, "|%*s|", 50, "ФИО");
	fprintf(file, "%*s|", 20, "ОТДЕЛ");
	fprintf(file, "%*s|", 20, "ДОЛЖНОСТЬ");
	fprintf(file, "%*s|\n", 20, "ОКЛАД");
	fprintf(file, "+%s+\n", buffer);
	// Данные
	for(size_t i = 0; i < size1; i++)
	{
		fprintf(file, "|%*s|", 50, data[i].FCs);
		fprintf(file, "%*s|", 20, data[i].office);
		fprintf(file, "%*s|", 20, data[i].post);
		fprintf(file, "%*d|\n", 20, data[i].payroll);
	}
	fprintf(file, "+%s+\n", buffer);
}

int main()
{
	setlocale(LC_ALL, "RU");

	FILE* infile = fopen("data.bin", "rb");

	struct WORKER workers[100];

	int size = 0;
	// запись данных в массив
	while (fread(&workers[size], sizeof(struct WORKER), 1, infile))
	{
		size++;
	}

	// вывод данных в консоль
	for(size_t i = 0; i < size; i++)
	{
		out(workers[i]);
	}

	// Запрос отдела у пользователя
	printf("Отдел: ");
	char* department = (char*)malloc(sizeof(char) * 50);
	scanf("%s", department);
	printf("\n");

	//Поиск отдела по структуре
	int flag = 0;
	for(size_t i = 0; i < size; i++)
	{
		if(strstr(workers[i].office, department))
		{
			out(workers[i]);
			flag = 1;
		}
	}
	// Проверка на выполнение вызова функции вывода
	flag == 0 ? printf("Данных нет\n") : printf("\n");

	printf("\n\n");
	// Сортировка
	for(size_t i = 0; i < size - 1; i++)
	{
		for(size_t j = 0; j < size - i - 1; j++)
		{
			if(strcmp(workers[j].FCs, workers[j + 1].FCs) > 0)
			{
				struct WORKER buffer = workers[j];
				workers[j] = workers[j + 1];
				workers[j + 1] = buffer;
			}
		}
	}
	// Отдел
	for(size_t i = 0; i < size - 1; i++)
	{
		for(size_t j = 0; j < size - i - 1; j++)
		{
			if(strcmp(workers[j].office, workers[j + 1].office) > 0)
			{
				struct WORKER buffer = workers[j];
				workers[j] = workers[j + 1];
				workers[j + 1] = buffer;
			}
		}
	}

	//Вывод
	for(size_t i = 0; i < size; i++)
	{
		out(workers[i]);
	}

	FILE* outfile = fopen("table.txt", "w+");
	out_to_table(workers, size, outfile);
	fclose(outfile);
}

