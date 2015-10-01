#include <sys/types.h> /* pid_t... */
#include <stdio.h>     /* printf... */
#include "proc-mesg.h"

char str_decale[3]="";
char str_identp[5]="pere";
char str_buffer[256];
pid_t pid=0;
pid_t ppid=0;

void printmsg(char *str_msg)
{
	printf("\n%sProc %d (%s) de pere %d : %s", str_decale, pid, str_identp, ppid, str_msg);
	fflush(stdout);
}
