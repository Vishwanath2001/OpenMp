#include<stdio.h>
#include<omp.h>
#include <stdlib.h>
int main(int argc, char const *argv[]){
    int largest=0;
    int arr[100000];
    for (int i = 0; i < 100000; i++)
    {
        arr[i]=rand();
        
    }
    #pragma omp parallel for num_threads(3) reduction(max: largest) 
    for(int j=0;j<100000;j++){
        if(arr[j]>largest){
            largest=arr[j];
        }
    }
    printf("Largest number in generated array of randoms is %d",largest); 
    return 0;

}