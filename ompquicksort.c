#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int partition(int * a, int p, int r)
{
    int lt[r-p];
    int gt[r-p];
    int i;
    int j;
    int key = a[r];
    int lt_n = 0;
    int gt_n = 0;
    

#pragma omp parallel for
    for(i = p; i < r; i++){
        if(a[i] < a[r]){
            lt[lt_n++] = a[i];
        }else{
            gt[gt_n++] = a[i];
        }   
    }   

    for(i = 0; i < lt_n; i++){
        a[p + i] = lt[i];
    }   

    a[p + lt_n] = key;

    for(j = 0; j < gt_n; j++){
        a[p + lt_n + j + 1] = gt[j];
    }   

    return p + lt_n;
    
}


void quicksort(int * a, int p, int r)
{
    int div;

    if(p < r){ 
        div = partition(a, p, r); 
#pragma omp parallel sections
        {   
#pragma omp section
            quicksort(a, p, div - 1); 
#pragma omp section
            quicksort(a, div + 1, r); 

        }
    }
    
}


int main(void)
{   int SIZE =1<<8;
	int a[SIZE];
    double start,end;
	for(int j=0;j<SIZE;j++)
	{
	    a[j]=rand()%SIZE;
	}
    int i;
    start=omp_get_wtime();

    quicksort(a, 0, 9);
    end=omp_get_wtime();
    int N = SIZE;

    for(i = 0;i < N; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("\nquick sort Time Parallel= %f",(end-start));
    return 0;
    
}