#include <stdlib.h>    /* EXIT_FAILURE... */
#include <sys/types.h> /* pid_t... */
#include <unistd.h>    /* fork */
#include <stdio.h>     /* printf, perror... */
#include <sys/wait.h>  /* waitpid */
#include <string.h>    /* strcpy */

#define DURATION 10

char str_decale[3]="";
char str_identp[5]="pere";
char str_buffer[256];

pid_t pid=0, ppid=0;

void printmsg(char *str_msg)
{
	printf("\n%sProc %d (%s) de pere %d : %s", str_decale, pid, str_identp, ppid, str_msg);
	fflush(stdout);
}

void adieu(void)
{
	printmsg("adieu ! ..........................");
}

int main(int argc, char **argv)
{
	pid_t pid_fils, pid_ret;
	int statut_fils;

	pid=getpid(); ppid=getppid();
	printmsg("Creation depuis le shell");
	
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
			strcpy(str_identp, "fils");
			strcpy(str_decale, "  ");
			pid=getpid(); ppid=getppid();
			printmsg("creation par processus pere");
				
			for(int i=1; i <= DURATION; i+=2)
				{
					printmsg("toujours vivant");
					sleep(2);
				}
			
			exit(EXIT_SUCCESS);
			/* FIN DU PROCESSUS FILS */
			
		default:
			/* Suite du processus pere */
			sprintf(str_buffer, "creation d'un processus fils de pid %d", pid_fils);
			printmsg(str_buffer);
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
			printmsg("attente fils non termine");

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
					sprintf(str_buffer, "fin du fils de pid %d (pid demande = %d)", pid_ret, pid_fils);
					printmsg(str_buffer);
				}

			break;
			
		default:
			/* Le processus fils attendu est termine. */
			sprintf(str_buffer, "fin du fils de pid %d (pid demande = %d)", pid_ret, pid_fils);
			printmsg(str_buffer);
		}
	
	return EXIT_SUCCESS;
}

	
