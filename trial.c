#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int tid, i;
    clock_t t;
    t = clock();

    #pragma omp parallel
    {
        tid = omp_get_thread_num();
        printf("\n");
        printf("=============================================================================\n");
        printf("                   Thread no. %d execution starts\n", tid);
        printf("=============================================================================\n");
        #pragma omp for
            for(i=0; i<10000; i++)
                printf("%d ", rand()%1000);

        printf("\n");
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 

    printf("It took %f seconds to generate random numbers \n", time_taken);

    return 0;
}