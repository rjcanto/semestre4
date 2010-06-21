#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <stdio.h>      /* printf(),fprintf() */
#include <sys/socket.h> /* socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* sockaddr_in , inet_addr() */
#include <stdlib.h>     /* atoi() , exit() */
#include <string.h>     /* memset() */
#include <unistd.h>     /* close() */

	#define DEFAULT_UDP_PORT 7
	#define MAX_VALOR 15

#endif
