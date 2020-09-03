#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int *a;
void *fib(void* N)
{
	int i;
	int *n=(int*)N;
	if(*n==1)
	{
	a[0] = 0;
	pthread_exit(0);	
	}
	else if(*n==2)
	{
	a[0] = 0;a[1]=1;
	pthread_exit(0);	
	}
	a[0] = 0; a[1] = 1;  
    for (i = 2; i < *n; i++)  
    {    
       a[i] = a[i-1] + a[i-2];       
    }

}
 int main()
 {
 	int n,i;
 	pthread_t tid;
 	scanf("%d",&n);
 	a=(int *)malloc(sizeof(int)*n);
 	pthread_create(&tid,NULL,fib,(void*)&n);
 	pthread_join(tid,NULL);
 	for(i=0;i<n;i++)
 	printf("%d ",a[i]);
 	return 0;
 }
