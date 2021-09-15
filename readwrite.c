#include<stdio.h>
#include<omp.h>
omp_lock_t writelock;
omp_lock_t readlock;
omp_lock_t mutex;
int readcount=0;
int tid=-1;
void reader(int rc)
{
	printf("\n Thread id=%d read count=%d ", omp_get_thread_num(),rc);
	omp_set_lock(&readlock);
		readcount++;
			if(readcount==1)
				omp_set_lock(&writelock);
	omp_unset_lock(&readlock);
	printf("R[%d] reader is entering critical section \n",rc);
	printf("R[%d] reader is leaving critical section \n",rc);
	
	omp_set_lock(&readlock);
		readcount--;
			if(readcount==0)
				omp_unset_lock(&writelock);
				omp_unset_lock(&readlock);
}
void writer(int wc)
{
	printf("\n thread id= %d write count= %d",omp_get_thread_num(),wc);
	omp_set_lock(&writelock);
	printf(" W[%d] write is entering critical section \n",wc);
	omp_unset_lock(&writelock);	
	printf(" W[%d] write is leaving critical section \n",wc);
	
}
int main()
{
	omp_init_lock(&writelock);
	omp_init_lock(&readlock);
	omp_init_lock(&mutex);
#pragma omp parallel shared(writelock,mutex)private(tid)	
{
		
		omp_set_num_threads(6);
		#pragma omp single
		{reader(1);}
		#pragma omp single
		{reader(2);}
		#pragma omp single
		{reader(3);}
		#pragma omp single
		{writer(1);}
		#pragma omp single
		{reader(4);}
		#pragma omp single
		{writer(2);}
	}


  
omp_destroy_lock(&writelock);
omp_destroy_lock(&readlock);
omp_destroy_lock(&mutex);
}
