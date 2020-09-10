#include <stdio.h>
#include <stdlib.h>
typedef struct semaphore{
    int s;
}semaphore;
void P(semaphore S)
{
    while(S.s<=0);
    S.s--;
}
void V(semaphore S)
{
    S.s++;
}
int main()
{
    semaphore S;
    S.s=1;
    int t=10;
    int pid=fork();
    while(t--){
    if(pid==0)
    {
        P(S); 
        printf("Child critical section\n");
        V(S); 
    }
    else
    {
        P(S);
        printf("Parent critical section\n");
        V(S);
    }
    }
}
