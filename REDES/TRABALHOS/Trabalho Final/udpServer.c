#include "udpServer.h"


static int sumAll(int nbr){
	int val=0;
	
	while (nbr){
		val += nbr%10;
		
		nbr=nbr/10;
		
	}
	return val;
}

static int prodAll(int nbr){
	int val=1;

	while (nbr){
		val = val*(nbr%10);
		
		nbr  = nbr/10;
	}
	return val;
}

int main(int argc, char** argv){
    int sock;                        
    struct sockaddr_in echoServAddr; 
    struct sockaddr_in echoClntAddr; 
    unsigned int cliAddrLen;         
    char echoBuffer[MAX_VALOR];        
    unsigned short echoServPort;     
    int recvMsgSize; 
    int nbr,val; 
    char*  response;               
    char*  response2;  

    if (argc != 2)         
    {
        fprintf(stderr,"Sintaxe: %s <Porto do Servidor UDP>\n", argv[0]);
        exit(1);
    }

    echoServPort = atoi(argv[1]);  

    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        fprintf(stderr,"Não foi possível abrir o socket()");

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;               
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServAddr.sin_port = htons(echoServPort);     

    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        fprintf(stderr,"Não foi possível fazer bind()");
  
    for (;;)
    {
        
        cliAddrLen = sizeof(echoClntAddr);

        
        if ((recvMsgSize = recvfrom(sock, echoBuffer, MAX_VALOR, 0,
            (struct sockaddr *) &echoClntAddr, &cliAddrLen)) < 0)
            fprintf(stderr,"A função recvfrom() falhou");

        printf("Processando o cliente %s\n", inet_ntoa(echoClntAddr.sin_addr));

		if ( sscanf( echoBuffer, "%d", &val ) == 0 )
		{
			puts("Not a Number");
			response="Not a Number";
			sendto(sock, response, strlen(response), 0,(struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
		}else{

			response=(char*)calloc(1, 20);
			nbr=sumAll(val);
			if (sprintf(response,"%d",nbr) == 0 )
			{
				puts("Not a Number");
				response="Not a Number";
			}	;
			
			sendto(sock, response, strlen(response), 0,(struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));
			free(response);

			response2=(char*)calloc(1, 20);
			nbr=prodAll(val);
			
			if (sprintf(response2,"%d",nbr) == 0 )
			{
				puts("Not a Number");
				response2="Not a Number";
			}	;
			
			sendto(sock, response2, strlen(response2), 0,(struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr));

			free(response2);
			
		}
		
    }

	exit(0);
}
