#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand (time(NULL));
    FILE* file = fopen("f1.bin", "rb");
    FILE* f2 = fopen("out.txt", "w+");

   // int n, m, i, j, k, max, t, t1, r;
   // float a, b, t, t1; 
   int n, m;
    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    float** mas = (float**)malloc(sizeof(float*)*n);
    float** mas2 = (float**)malloc(sizeof(float*)*n);

    for (int i = 0; i < n; i++)
    {
        mas[i] = (float*)malloc(sizeof(float)*m);
        mas2[i] = (float*)malloc(sizeof(float)*m);
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
           fread(&mas[i][j], sizeof(float), 1, file);
           mas2[i][j] = mas[i][j];
        }
    }
    
    printf ("\n original \n");
	fprintf(f2, "\noriginal\n\n");

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf ("\t %.2f ",mas[i][j]);
    	    fprintf(f2,"\t %.2f ",mas[i][j]);
        }
        printf ("\n");
	fprintf(f2, "\n");
    }
	fprintf(f2, "\n\nz1\n");

    printf (" z1 ");
    //упорядочить элементы в каждом СТОЛБЦЕ по убыванию методом ВЫБОРА
   
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n-1; j++)
        {
           int max=j; 
            for (int k=j+1; k<n; k++)
            {
                if (mas[k][i]>mas[max][i])
                {
                    max=k;
                }
            }
            float t=mas[j][i];
            mas[j][i]=mas[max][i];
            mas[max][i]=t;
        }
    }
    printf ("\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("\t%.2f ",mas[i][j]);
    	    fprintf(f2,"\t%.2f ",mas[i][j]);
        }
        printf ("\n");
	fprintf(f2, "\n");
    }
   	fprintf(f2, "\n\nz2\n");
    //упорядочить элементы в СТРОКАХ матрицы по убыванию, используя метод ВСТАВКИ
    for (int k = 0; k < n; k++)
    {
        for (int i = 1; i < m; i++) {

        float key = mas2[k][i];
        int j = i - 1;
 
        while (j >= 0 && mas2[k][j] < key) {
            mas2[k][j + 1] = mas2[k][j];
            j = j - 1;
        }
        mas2[k][j + 1] = key;
    }
    }
    
    printf ("\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("\t %.2f ",mas2[i][j]);
    	    fprintf(f2,"\t%.2f ",mas[i][j]);

        }
        printf ("\n");
	fprintf(f2, "\n");
    }
	fprintf(f2, "\n\n");

	fclose(f2);
    for (int i = 0; i < m; i++)
    {
        free(mas[i]);
    }
    free(mas);
    return 0;
}