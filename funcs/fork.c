#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int stat;
	printf("parent pid = %u\n", getpid());
	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if(pid == 0)
	{
		printf("After fork\n");
		printf("child is %u\n", getpid());
		sleep(20);
		printf("wait");
	}
	else
	{
	//	wait(&stat);
		printf("After fork\nparent pid %u\n",  getpid());
	}
	return (0);
}
