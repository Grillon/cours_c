#include <stdlib.h>    /* EXIT_FAILURE... */
#include <sys/types.h> /* pid_t... */
#include <unistd.h>    /* fork */
#include <stdio.h>     /* printf, perror... */
#include <sys/wait.h>  /* waitpid */
#include <string.h>    /* strcpy */
#include <signal.h>    /* sigaction... */

#include "proc-fils.h" /* execute_fils */
#include "proc-sign.h" /* execute_handler */
#include "proc-mesg.h" /* printmsg */

#define DURATION 20



void adieu(void)
{
	printmsg("adieu ! ..........................");
}


int main(int argc, char **argv)
{
	pid_t pid_fils, pid_ret;
	int statut_fils;
	int i;
	struct sigaction S;
	

	pid=getpid(); ppid=getppid();
	printmsg("Creation depuis le shell");
	

	/* 1. Fonction en cas de terminaison du processus.
		 NB : elle sera heritee par le processus fils. */
	atexit(adieu);

  /* 1bis. Handler sur signal */
  S.sa_handler = execute_handler;

  if( sigfillset( &S.sa_mask ) != 0 ) /* Masque complet */
		{
			perror("main/sigfillset");
      exit(EXIT_FAILURE);
		}
	
	if( sigdelset( &S.sa_mask, SIGQUIT ) != 0 ) /* sauf SIGQUIT */
		{
			perror("main/sigdelset");
			exit(EXIT_FAILURE);
		}

  S.sa_flags = SA_NOCLDSTOP | SA_RESTART; 
  
  if( sigaction(SIGUSR1, &S, NULL) != 0 )
		{
			perror("main/sigaction");
			exit(EXIT_FAILURE);
		}


	/* 2. Creation du processus fils */
	switch ( pid_fils = fork() )
		{
		case (pid_t)-1:
			/* Echec du fork */
			perror("main/fork");
			exit(EXIT_FAILURE);

		case (pid_t)0:
			/* DEBUT PROCESSUS FILS */
			execute_fils();
			
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

	/* 5. Examen du code de retour du processus fils */
	if( WIFEXITED(statut_fils) != 0 )
		{
			sprintf(str_buffer, "code de retour du fils %d = %d",
							(int)pid_fils,
							WEXITSTATUS(statut_fils));
			printmsg(str_buffer);
		}
	
	if( WIFSIGNALED(statut_fils) != 0 )
		{
			sprintf(str_buffer, "fin du fils %d due au signal %d non intercepte",
							(int)pid_fils,
							WTERMSIG(statut_fils));
			printmsg(str_buffer);
		}
	
	if( WIFSTOPPED(statut_fils) != 0 )
		{
			sprintf(str_buffer, "processsus fils %d stoppe par signal %d",
							(int)pid_fils,
							WSTOPSIG(statut_fils));
			printmsg(str_buffer);
		}
	
	
	return EXIT_SUCCESS;
}

	
