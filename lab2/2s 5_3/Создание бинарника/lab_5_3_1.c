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

void reader(FILE* infile, FILE* outfile)
{
	struct WORKER data;

	while(!feof(infile))
	{
		fgets(data.FCs, 50, infile);
		data.FCs[strlen(data.FCs) - 1] = 0; // Удаление \n

		fgets(data.office, 50, infile);
		data.office[strlen(data.office) - 1] = 0;

		fgets(data.post, 50, infile);
		data.post[strlen(data.post) - 1] = 0;

		fscanf(infile, "%d\n", &data.payroll);

		out(data); // Вывод

		fwrite(&data, sizeof(struct WORKER), 1, outfile);
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	FILE* infile = fopen("in.txt", "r");
	FILE* outfile = fopen("data.bin", "w+");
	reader(infile, outfile);

	fclose(infile);
	fclose(outfile);
}