#include <stdio.h>
int main(int ac, char **av, char **env)
{
    unsigned int i;
    i = 0;
    while (env[i] != NULL)
    {
        printf("argv[%d] \t : %s\n", i, env[i]);
        i++;
    }
    return (0);
}
