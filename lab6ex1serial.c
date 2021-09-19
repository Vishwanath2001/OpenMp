#include<stdio.h>
#include <stdlib.h>
int main(){
    int largest=0;
    int arr[100000];
    for (int i = 0; i < 100000; i++)
    {
        arr[i]=rand();
        
    }
    
    for(int j=0;j<100000;j++){
        #pragma omp critical
        if(arr[j]>largest){
            largest=arr[j];
        }
        
    }
    

    printf("Largest number in generated array of randoms is %d",largest); 

}