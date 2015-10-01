#include <stdio.h>


enum socket_state{ESTABLISHED, SYN_SENT, SYN_RECV, FIN_WAIT1, FIN_WAIT2, TIME_WAIT, CLOSE, CLOSE_WAIT, LAST_ACK, LISTEN, CLOSING, UNKNOWN};

/* cf. man netstat pour des informations sur l'état des sockets */
void print_socket_state(enum socket_state s)
{
	switch(s)
		{
		case LISTEN:
			printf("La socket attend une connexion.\n");
			break;
		case SYN_RECV:
			printf("La socket a reçu une demande de connexion.\n");
			break;
		case SYN_SENT:
			printf("La socket essaye d'établir la connexion.\n");
			break;
		case ESTABLISHED:
			printf("La connexion est établie.\n");
			break;
		case FIN_WAIT1:
		case FIN_WAIT2:
		case TIME_WAIT:
		case CLOSE_WAIT:
		case LAST_ACK:
		case CLOSING:
			printf("La connexion est en cours de fermeture.\n");
			break;
		case CLOSE:
			printf("La socket n'est pas utilisée.\n");
			break;
		case UNKNOWN:
			printf("L'état de la socket est inconnu.\n");
			break;
		default:
			printf("L'état de la socket n'est pas documenté.\n");
		}
	
}




	
	
int main(void)
{

enum socket_state s1=UNKNOWN, s2=CLOSING, s3=100;


print_socket_state(s1);
print_socket_state(s2);
print_socket_state(s3);

return 0;

}
