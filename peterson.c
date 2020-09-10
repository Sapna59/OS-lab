#include <stdio.h>
#include <stdlib.h>
int main()
{
    int turn,t=100;
    int pid=fork();
    int flag[]={0,0};
    if(pid==0)
    {
        while(t--){
        flag[0] = 1; 
        turn = 1; 
        while (flag[1] == 1 && turn == 1); 
        printf("Child critical section\n");
        flag[0] = 0;} 
    }
    else
    {
        while(t--){ 
        flag[1] = 1; 
        turn = 0; 
        while (flag[0] == 1 && turn == 0) ;
        printf("Parent critical section\n");
        flag[1] = 0; }
    }
}
