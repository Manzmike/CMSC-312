/*
 * shm-client - client program to demonstrate shared memory.
 * shm-client - not sure of the origin of these code segments.
 * possibly: David Marshalls course : http://www.cs.cf.ac.uk/Dave/C/CE.html
 * or Steve Holmes : http://www2.its.strath.ac.uk/courses/c/
 */

//PROCESS B
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ     27
int
main()
{
    int shmid;
    key_t key1,key2;
    char *shm_char, *s1;
    int *shm_int, *s2;
    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key1 = 5678;
    key2 = 8765;




    //CHAR
    /*
     * Locate the segment.
     */
    if( (shmid = shmget(key1, SHMSZ, 6000)) < 0 )
    {
        perror("shmget");
        exit(1);
    }
    /*
     * Now we attach the segment to our data space.
     */
    if( (shm_char = shmat(shmid, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }


    //INT
    /*
     * Locate the segment.
     */
    if( (shmid = shmget(key2, SHMSZ, 6000)) < 0 )
    {
        perror("shmget");
        exit(1);
    }
    /*
     * Now we attach the segment to our data space.
     */
    if( (shm_int = shmat(shmid, NULL, 0)) == (int *) -1 )
    {
        perror("shmat");
        exit(1);
    }







/*
     * Now read what the server put in the memory.
     */
    for( s1 = shm_char; *s1 != (char) NULL; s1++ )
        putchar(*s1);
    putchar('\n');
    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */
    *shm_char = '*';
    return 0;
}