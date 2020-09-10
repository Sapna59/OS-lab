#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void check();
int main()
{
        pid_t pid;
        int i;
        pid=fork();
        if(pid==0)
            check();
        else
            check();
    return 0;
}
void check()
{
        int i;
        for(i=0;i<1000;i++)
        printf("%d ",i);
        printf("\n");
}
