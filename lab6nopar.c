#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int i;
    int arr[1000000];
    
    for(int i=0;i<1000000;i++){
        arr[i]=rand();
    }
    float sum=0.0,mean,SD=0.0;
    
    for(int k=0;k<1000000;++k){
        sum += arr[k];

    }
    mean=sum/10;
    for(int j=0;j<1000000;j++){
        SD += pow(arr[i] - mean, 2);
    }
    
    printf("%f",sqrt(SD/10));
    return 0;
}
