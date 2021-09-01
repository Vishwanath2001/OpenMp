#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <limits.h>
int main()
{
int a[10000], b[10000];
int sum=0;
int min=INT_MAX;
int i;
double time_taken[2];
clock_t t,t1,t2;
for(int i=0;i<10000;i++)
a[i]=rand()%100;
#pragma omp parallel shared(sum,min) private(i)
{
#pragma omp sections nowait
{
#pragma omp section
{
t=clock();
for(i=0;i<10000;i++)
{
sum+=a[i];
b[i]=sum;
}
t=clock()-t;
time_taken[0]= ((double)t)/CLOCKS_PER_SEC;
}
#pragma omp section
{
t1=clock();
for(i=0;i<10000;i++)
{
if(a[i]<min)
min=a[i];
}
t1=clock()-t1;
time_taken[1]= ((double)t1)/CLOCKS_PER_SEC;
}
}
}
printf("Prefix sum for 100 elementa\n");
for (int i=0;i<100;i++)
printf("%d ",b[i]);
printf("\nTime Taken: %fs\n\n",time_taken[0]);
printf("\nMinimum numbber in an array = %d\n",min);
printf("Time Taken:%fs\n\n",time_taken[1]);
return 0;
}