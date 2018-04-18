/*
 * Order of creation and "named" of a UNIX domain socket.
 * The name of the socket is given as a parameter.
 */

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>

int main(n, v)
	int n;char *v[]; {
	int sock;                       /* Socket descriptor */
	static struct sockaddr_un adr;  /* Socket address */

	if (n != 2) {
		fprintf(stderr, "parameter error\n");
		exit(2);
	}

	sock = socket(AF_UNIX, SOCK_DGRAM, 0);

	if(sock == -1){
		perror("socket");
		exit(2);
	}

	adr.sun_family = AF_UNIX;
	bcopy(v[1], adr.sun_path, strlen(v[1]));

	if(bind(sock, (void*) &adr, sizeof(adr)) == -1){
		perror("bind");
		exit(2);
	}

	printf("Successfuly link!\n");
	while(1);
}
