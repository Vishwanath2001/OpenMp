#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<omp.h>
void main(){
int thread_id;
#pragma omp parallel
{
thread_id=omp_get_thread_num();
printf("Vishwanath B Bhat -19BCE1499=%d \n",thread_id);

}
}
