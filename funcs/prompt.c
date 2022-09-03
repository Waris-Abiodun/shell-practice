#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	char *buf = NULL;
	int i = 1;
	ssize_t num_read;
	size_t mem_al = 2;
	const char *sep = "> \n\t";
	char *token;

	char **argv;
	char *buf_cpy;
	

	while (i > 0)
	{
		printf("welcome to shell$ ");
		num_read = getline(&buf, &mem_al, stdin);
		if (num_read == -1)
		{
			perror("end of file encountered\n");
			return (0);
		}

		buf_cpy = malloc(num_read);
		strcpy(buf_cpy, buf);

		token = strtok(buf_cpy, sep);
		int count = 1;
		while (token)
		{
			token = strtok(NULL, sep);
			count ++;
		}
		token = NULL;
		free(token);
		free(buf_cpy);
		argv = malloc (count);

		token = strtok(buf, sep);
		int n = 0;
		while(token)
		{
			
			argv[n] = malloc(sizeof(char) *strlen(token));
			strcpy(argv[n], token);
		//	printf("argv[%d] : %s\n", n , argv[n]);
			token = strtok(NULL, sep);
			n++;

		}
		argv[n] = NULL;
		if (strcmp(argv[0], "exit") == 0)
		{
			printf("exiting...\n");
			return 0;
		}
					/*** execution**/
		pid_t child;
		child = fork();
		int stat;
		if(child == -1)
		{
			perror("child cant be created");

		}
		else if (child == 0)
		{

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("unable to execute fuction");
			}
		}
		else
		{
			wait(&stat);
		}


	}
	
	return (0);
}
