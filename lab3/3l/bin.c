#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *fbName = "f1.bin";

float rand_n()
{
    float min = 0.125;
    float max = 100.865;
    return (float)(rand())/RAND_MAX*(max - min) + min;
}

int main() {
  srand(time(NULL));
  FILE *file;
  int n, m;
  if ((file = fopen(fbName, "wb")) == NULL) {
    printf("Fail %s dont open", fbName);
    return 1;

  } else {

    float temp = 0;
    n = rand() % (10 - 6 + 1) + 6;
    m = rand() % (10 - 6 + 1) + 6;

    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);

    for (int i = 0; i < n*m; i++) {
        temp =  rand_n();
        printf("%f\t", temp);
        fwrite(&temp, sizeof(float), 1, file);
    }
    fclose(file);
  }
  return 0;
}