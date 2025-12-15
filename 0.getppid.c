#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("Parent process ID: %d\n", getppid());
    return 0;
}