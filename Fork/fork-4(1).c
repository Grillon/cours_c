#include <stdlib.h>    /* EXIT_FAILURE... */
#include <sys/types.h> /* pid_t... */
#include <unistd.h>    /* fork */
#include <stdio.h>     /* printf, perror... */
#include <sys/wait.h>  /* waitpid */

#define DURATION 10

void adieu(void)
{
	printf("\n Proc %d : adieu ! ...................\n",getpid());
	fflush(stdout);
}

int main(int argc, char **argv)
{
	pid_t pid_fils, pid_ret;
	int statut_fils;

	/* 1. Fonction en cas de terminaison du processus.
		 NB : elle sera heritee par le processus fils. */
	atexit(adieu);
	
	/* 2. Creation du processus fils */
	switch ( pid_fils = fork() )
		{
		case (pid_t)-1:
			/* Echec du fork */
			perror("main/fork");
			exit(EXIT_FAILURE);

		case (pid_t)0:
			/* DEBUT PROCESSUS FILS */
			printf("\n Proc %d : creation par processus pere %d\n", getpid(), getppid());

			for(int i=1; i <= DURATION; i+=2)
				{
					printf("\n Proc %d (fils) toujours vivant", getpid());
					fflush(stdout);
					sleep(2);
				}
			
			exit(EXIT_SUCCESS);
			/* FIN DU PROCESSUS FILS */
			
		default:
			/* Suite du processus pere */
			printf("\n Proc %d (de pere %d) : creation d'un processus fils %d \n",
						 getpid(), getppid(), pid_fils);
			fflush(stdout);
		}
	
	/* 3. Attente non bloquante du processus fils */
	switch ( pid_ret = waitpid(pid_fils, &statut_fils, WNOHANG) )
		{
		case (pid_t)-1:
			/* Echec du waitpid */
			perror("main/waitpid WNOHANG");
			exit(EXIT_FAILURE);
			
		case (pid_t)0:
			/* Le processus fils attendu n'est pas termine */
			printf("\n Proc %d : attente fils %d non termine", getpid(), pid_fils);
			fflush(stdout);

			/* 4. Attente bloquante du processus fils */
			switch( pid_ret =waitpid(pid_fils, &statut_fils, WUNTRACED) ) 
				{
				case (pid_t)-1:
					/* Echec du waitpid() */
					perror("main/waitpid WUNTRACED -1");
					exit(EXIT_FAILURE);

				case (pid_t)0:
					/* Ne devrait pas se produire */
					perror("main/waitpid WUNTRACED 0");
					exit(EXIT_FAILURE);

				default:
					/* Le processus fils attendu est termine */
					printf("\n Proc %d : fin du fils de pid %d (pid demande = %d)", getpid(), pid_ret, pid_fils);
					fflush(stdout);
				}
			break;
			
		default:
			/* Le processus fils attendu est termine. */
			printf("\n Proc %d : fin du fils de pid %d (pid demande = %d)", getpid(), pid_ret, pid_fils);
			fflush(stdout);
		}
	
	return EXIT_SUCCESS;
}

	
