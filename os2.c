#include <stdio.h>
#include <stdlib.h> 
#include<sys/wait.h> 
int main()
{
    int pid=fork();
    if(pid==0)
    printf("Child process %d\n",pid);
    else 
    printf("Parent process %d\n",pid);
    return 0;
}
