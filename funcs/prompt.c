#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

		token = strtok(buf, sep);
		int count = 1;
		while (token)
		{
			token = strtok(NULL, sep);
			count ++;
		}
		argv = malloc (count);

		token = strtok(buf_cpy, sep);
		int n = 0;
		while(token)
		{
			argv[n] = malloc(sizeof(char) *strlen(token));
			strcpy(argv[n], token);
			printf("argv[%d] : %s\n", n , token);
			n++;
			token = strtok(NULL, sep);

		}
		/*** execution**/
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("unable to execute fuction");
		}


	}
	return (0);
}
