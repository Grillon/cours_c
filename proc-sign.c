#include <stdio.h>     /* sprintf */
#include "proc-mesg.h" /* str_buffer, printmsg */
#include "proc-sign.h" /* DURATION_HANDLER + bon usage */

void execute_handler(int n)
{
	int i;
	
	sprintf(str_buffer, "handler du signal %d", n);
	printmsg(str_buffer);
	
	for(i=0; i < DURATION_HANDLER; i++) 
		{
			sleep(2);
			printmsg("handler en cours d'execution");
		}

	printmsg("fin du handler");
}
