#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *argv[];
	size_t n = 0;
	argv = malloc(100);
	printf("%s\n", argv[0]);
	printf("Before execve\n");
	if (execve("/bin/ls", argv, NULL) == -1);
	{
		perror("Error:");
	
	}
	printf("Today is a good day");
	printf("After execve\n");
	return (0);
}
