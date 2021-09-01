#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
void *myThreadFun(void *vargp)
{
int *myid=(int *)vargp; printf("Thread 1 prints:PDC\n");


}
void *myThreadFun2(void *vargp)
{
int *myid=(int *)vargp;
printf("Thread 2 prints:LAB\n");

}


int main()
{
pthread_t thread_id; int i=1;

pthread_create(&thread_id, NULL, myThreadFun, (void *)&i); i=2;
pthread_create(&thread_id, NULL, myThreadFun2, (void *)&i); pthread_exit(NULL);
return 0;
}
