#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    (void) ac;
    i = 0;
    while (av[i] != NULL)
    {
        printf("AV: %s\n", av[i]);
        i++;
    }

    return 0;
}