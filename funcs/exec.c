#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	//printf("%s\n", env[0]);
	char **argv;
	argv = malloc(300);
	int stat;
	argv[0] = "/bin/ls";
	argv[1] =  "-l";
	argv[2] = "/tmp/";
	argv[3] = NULL;


	pid_t child;
	   int i;
	   for(i = 0; i<5; i++)
	   {
	    child = fork();
	    if (child == -1)
	    {
		    perror("forking failed");
		    return -1;
	    }
	    else if (child == 0)
	    {

		    if (execve(argv[0], argv, NULL) == -1)
		    {
			    perror("new ERROr::");
		    }
		    sleep(3);
	    }
	    else 
	    {
		    wait(&stat);
		    printf("parent\n");
	    }
	   }
	   printf("done\n");
	    return (0);
}
