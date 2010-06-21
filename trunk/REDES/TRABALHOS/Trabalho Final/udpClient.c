#include "udpClient.h"
	#define DEFAULT_UDP_PORT 7
	#define MAX_VALOR 15
int main(int argc, char** argv){
	int sock;                        
	struct sockaddr_in echoServAddr;
	struct sockaddr_in fromAddr;
	unsigned short echoServPort;
	unsigned int fromSize;
	char *servIP;
	char *valor;
	char echoBuffer[MAX_VALOR+1];
	int valorLen;
	int respStringLen;

    if ((argc < 3) || (argc > 4))
    {
        fprintf(stderr,"Sintaxe: %s <IP do Servidor> <valor> [<porto>]\n", argv[0]);
        exit(1);
    }

    servIP = argv[1];
    valor = argv[2];

	
    if ((valorLen = strlen(valor)) > MAX_VALOR)  
        fprintf(stderr,"Echo word too long");
	
	
    if (argc == 4)
        echoServPort = atoi(argv[3]);  
    else
        echoServPort = DEFAULT_UDP_PORT;  

    
    
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        fprintf(stderr,"socket() failed");
    
    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));    /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                 /* Internet addr family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);  /* Server IP address */
    echoServAddr.sin_port   = htons(echoServPort);     /* Server port */

    /* Send the string to the server */
    if (sendto(sock, valor, valorLen, 0, (struct sockaddr *)
               &echoServAddr, sizeof(echoServAddr)) != valorLen)
        fprintf(stderr,"sendto() sent a different number of bytes than expected");
  
    /* Recv a response */
    fromSize = sizeof(fromAddr);
    respStringLen=recvfrom(sock, echoBuffer, MAX_VALOR, 0, (struct sockaddr *) &fromAddr, &fromSize);
    /*
    if ((respStringLen = recvfrom(sock, echoBuffer, MAX_VALOR, 0, (struct sockaddr *) &fromAddr, &fromSize)) != valorLen)
        fprintf(stderr,"recvfrom() failed");
*/
    if (echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
    {
        fprintf(stderr,"Error: received a packet from unknown source.\n");
        exit(1);
    }

    /* null-terminate the received data */
    echoBuffer[respStringLen] = '\0';
    printf("Received: %s\n", echoBuffer);    /* Print the echoed arg */
    
    respStringLen=recvfrom(sock, echoBuffer, MAX_VALOR, 0, (struct sockaddr *) &fromAddr, &fromSize);
    /* null-terminate the received data */
    echoBuffer[respStringLen] = '\0';
    printf("Received: %s\n", echoBuffer);    /* Print the echoed arg */
    
    close(sock);
    exit(0);
}
