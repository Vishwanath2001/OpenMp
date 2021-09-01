#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<omp.h>
int main(){
    long long int partial_even_sum,partial_odd_sum,even_sum,odd_sum,arr[10000];
    #pragma omp parallel private(partial_even_sum,partial_odd_sum) shared(even_sum,odd_sum)
    {
        partial_even_sum=0;
        partial_odd_sum=0;
        even_sum=0;
        odd_sum=0;
        //assuming we have to apply parllel for loop iteration when we are 
        //calculating sum of odd and even and not while creating array
        for(long long int i=0;i<10000;i++){
            arr[i]=i; 
        }
        #pragma omp parallel for schedule(static,50)
        for(long long int j=0;j<10000;j++){
            if(arr[j]%2==0){
                partial_even_sum=partial_even_sum+arr[j];
            }
            else{
                partial_odd_sum=partial_odd_sum+arr[j];
            }

        }

        #pragma omp critical
        {
            even_sum+=partial_even_sum;
            odd_sum+=partial_odd_sum;
        }





    }
    printf("Even sum->%lld",even_sum);
    printf("\nOdd sum>%lld",odd_sum);
}
    

