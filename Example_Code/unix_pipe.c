/**
 * Example program demonstrating UNIX pipes.
 *
 * Figures 3.23 & 3.24
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Eighth Edition
 * Copyright John Wiley & Sons - 2008.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 2500
#define READ_END	0
#define WRITE_END	1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings from CMSC312 at VCU";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int fd[2];

    /** create the pipe */
    if (pipe(fd) == -1) {
        fprintf(stderr,"Pipe failed");
        return 1;
    }
//printf("fd[0]=%d fd[1]=%d\n", fd[0], fd[1]);

    /** now fork a child process */
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) {  /* parent process */
        /* close the unused end of the pipe */
        close(fd[READ_END]);

        /* write to the pipe */
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

        /* close the write end of the pipe */
        close(fd[WRITE_END]);
    }
    else { /* child process */
        /* close the unused end of the pipe */
        close(fd[WRITE_END]);

        /* read from the pipe */
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("child read from parent:  [%s]\n",read_msg);

        /* close the write end of the pipe */
        close(fd[READ_END]);
    }

    return 0;
}