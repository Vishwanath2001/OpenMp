//simple openmp program to demonstrate single constructor
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char const *argv[])
{
    int x=0;
    #pragma omp parallel num_threads(4)
    {   
        for(int i=0;i<5;i++){
            #pragma omp master
            x++;
        }
        
       
    }
    printf("Incremented x value after synchronization:%d",x);
    return 0;
}
