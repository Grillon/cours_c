#include <stdlib.h>    /* EXIT_FAILURE... */
#include <sys/types.h> /* pid_t... */
#include <unistd.h>    /* fork */
#include <stdio.h>     /* printf, perror... */

#define DURATION 60

int main(int argc, char **argv)
{
	pid_t pid_fils;
	
	switch ( pid_fils = fork() )
		{
		case (pid_t)-1:
			perror("main/fork");
			exit(EXIT_FAILURE);

		case (pid_t)0:
			/* Processus fils */
			printf("\n Proc %d : creation par processus pere %d\n", getpid(), getppid());

			for(int i=1; i <= DURATION; i+=2)
				{
					printf("\n Proc %d (fils) toujours vivant", getpid());
					fflush(stdout);
					sleep(2);
				}
			
			printf("\n Proc %d : fin !.......................\n", getpid());
			exit(EXIT_SUCCESS);
			
		default:
			printf("\n Proc %d (de pere %d) : creation d'un processus fils %d \n",
						 getpid(), getppid(), pid_fils);
			printf("\n Proc %d : fin !.......................\n", getpid());
			fflush(stdout);
		}
	
	return EXIT_SUCCESS;
}

	
