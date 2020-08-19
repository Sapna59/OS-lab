#include <stdio.h>

int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		pid=fork();
		if(pid==0)
		{
			fork();
		}	
	}
	else
	{
		pid=fork();
		if(pid==0)
		{
			pid=fork();
			if(pid>0)
			{
				fork();
			}
		}
	}
	return 0;
}
