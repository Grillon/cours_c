#ifndef _PROC_MESG
#define _PROC_MESG

#include <sys/types.h>

extern char str_decale[];
extern char str_identp[];
extern char str_buffer[];

extern pid_t pid;
extern pid_t ppid;

void printmsg(char *str_msg);

#endif
