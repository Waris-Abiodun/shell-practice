#include <stdio.h>
//#include <sys/types.h> 
#include <unistd.h>
int main(void)
{
	pid_t pid;
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
	}
	else
	{
		printf("After fork\nparent pid %u\n",  getpid());
	}
	return (0);
}
