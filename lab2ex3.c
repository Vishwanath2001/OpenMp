#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<omp.h>
void main(){
int thread_id;
int i;
#pragma omp parallel
{
thread_id=omp_get_thread_num();
for(i=0;i<omp_get_max_threads();i++){
printf("Vishwanath B Bhat -19BCE1499=%d \n",thread_id);
}
}
}
