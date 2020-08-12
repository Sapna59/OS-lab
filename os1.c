#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<sys/wait.h> 
int main()
{
    int *a;
    int n,pid,i,j;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    pid=fork();
    if(pid==0)
    {
        a[0]=0;
        a[1]=1;
        for(i=2;i<n;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        for(j=0;j<n;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    else
    {
        
        wait(NULL);
        printf("Numbers printed successfully!!");
    }
    return 0;
}
