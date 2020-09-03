#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int g=10;
void *MyThread(void* N)
{
	static int s=3;
	int l=1;
	int *n=(int*)N;
	g++;l++; s++;
	printf("Thread_id %d, Global %d, Static %d, Local %d\n",*n,g,s,l);

}
 int main()
 {
 	int n,i;
 	pthread_t tid;
 	for(i=0;i<3;i++)
 	pthread_create(&tid,NULL,MyThread,(void*)&tid);
 	pthread_exit(0);
 	return 0;
 }
