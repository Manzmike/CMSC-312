/**
 * This program forks a separate process using the fork()/exec() system calls.
 *
 * Figure 3.10
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Eighth Edition
 * Copyright John Wiley & Sons - 2008.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int gloabl = 10;
int main()
{
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        sleep(1);
        printf("I am the child  pid %d\n",pid);
        printf("I am the child getpid():  %d\n",getpid());
        printf("I am the child getppid():  %d\n",getppid());
      //  execlp("/bin/ls","ls",NULL);
        execlp("/bin/date","date",NULL);
        gloabl = 5;

    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        printf("I am the parent of %d\n",pid);
        printf("Parent pid is %d\n",  getpid());
        printf("Parent ppid is %d\n",  getppid());
	pid = wait(NULL);

        printf("Child %d Complete\n", pid);
        printf("TEST");
        fprint(gloabl);
        int gloabl = 100;
        exit(0);
        

    }

    fprint(gloabl);
}