#include <stdio.h>
#include <omp.h>

#define MAX 10

int main() {
   int x = 0;
   #pragma omp parallel num_threads(MAX)
   {
      #pragma omp atomic
      x++;
   }
   printf("Number of threads: %d\n", x);
}