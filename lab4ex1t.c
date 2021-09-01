#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
int main(){
     double start, end,start1,end1;
   int SIZE =1<<8;
   int arr[SIZE];
   int N = SIZE;
   int n=123;
   for(int k=0;k<SIZE;k++)
	{
	    arr[k]=rand()%SIZE;
	}
    #pragma omp parallel shared(arr,SIZE,N,n,start,end,start1,end1) private(none){
        #pragma omp sections{
            #pragma omp section{
                start = omp_get_wtime();
                    int sum=0;
            for(int i=0;i<n;i++){
                    sum=sum+arr[i];
                                }
                printf("parallel sum of %d integer is%d",n,sum);
                end=omp_get_wtime();
                printf("Time for 1:%g",end-start);

            }
            #pragma omp section{
                start1=omp_get_wtime();
                 for(int j=0;j<size;j++){
        if(arr[j]<min){
            min=arr[j];
        }
    }
    printf("Minimum number in the array is %d",min);
    printf("Time for 1:%g",end1-start1);

            }
        }
    }
}