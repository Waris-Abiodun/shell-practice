#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;
    struct timespec tt;
    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
	    printf("Group ID: \t %ld",(long) st.st_gid);
	    printf("Last Access: \t %s", ctime(&st.st_atime));
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
}
