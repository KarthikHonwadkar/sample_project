// C program to illustrate
// pipe system call in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

int main()
{
    char* msg1="hello";
    char* msg2="welcome";
    char* msg3="bye";

    char buf[MSGSIZE];

    int fd[2], i;

    if (pipe(fd) < 0)
        exit(1);

    // continued to write pipe
    write(fd[1],msg1,MSGSIZE);
    write(fd[1],msg2,MSGSIZE);
    write(fd[1],msg3,MSGSIZE);

    for(i=0;i<3;i++)
    {
        // read pipe
        read(fd[0],buf,MSGSIZE);
        printf("%s\n",buf);
    }

    return 0;
}