// pipe system call
// shared by parent and child

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MSGSIZE 15

int main()
{
    char* msg1="hello";
    char* msg2="welcome";
    char* msg3="bye";

    char buf[MSGSIZE];

    int fd[2], pid, bytes;

    if(pipe(fd) < 0)
        exit(1);


    pid = fork();

    if(pid != 0)
    {
        //parent process
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);

        // sleep(4);
        // kill(pid,SIGKILL);
        wait(NULL);
    }

    else
    {
        //child process
        while((bytes = read(fd[0], buf, MSGSIZE)) > 0)
        {
            printf("%s\n", buf);
        }
        
        printf("Finished reading\n");
        if(bytes != 0)
            exit(2);
    }

    return 0;
}