#include <string.h>    /* strcpy */
#include "proc-fils.h" /* DURATION_FILS (+ le bon reflexe) */
#include "proc-mesg.h" /* printmsg, str_identp, str_decale... */


/* Definition de la fonction */
int execute_fils(void)
{
	int i;

	
	strcpy(str_identp, "fils");
	strcpy(str_decale, "  ");

	pid=getpid(); ppid=getppid();
	printmsg("creation par processus pere");
				
	for(i=1; i <= DURATION_FILS; i+=2)
		{
			printmsg("toujours vivant");
			sleep(2);
		}
}
