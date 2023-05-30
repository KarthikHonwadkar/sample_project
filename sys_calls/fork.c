#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PROC 3

//Creating 1 parent process and 3 child process

int main()
{
	int a[MAX_PROC];
	printf("parent process id = %d\n",getppid());
	for(int i=0;i<MAX_PROC;i++)
	{
		a[i]=fork();
		if(a[i]==0)
		{
			printf("Child process id = %d\n",getpid());
			//printf("patent process id = %d\n",getppid());
			exit(0);
		}
	}

	while(1);
}
