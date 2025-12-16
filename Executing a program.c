#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *argv[] = {"ls", "-l", "/tmp", NULL};
    extern char **environ;
printf("before execve\n");
if (execve("/bin/ls", argv, environ) == -1)
{
perror("error:");
}
printf("after execve\n");
    return (0);
}
