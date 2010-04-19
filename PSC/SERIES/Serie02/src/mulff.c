#include <stdio.h>
int mulff(float *res, float a, float b);

int main(){
	float fp=0;
	float a=0;
	float b=0;

	printf("Introduza o primeiro numero float:");
	scanf("%f",&a);
	
	printf("Introduza o segundo  numero float:");
	scanf("%f",&b);
	
	
	
	if (mulff(&fp,a,b))
		printf("[::Resultado da Função em assembly::]> %f \n",fp);
		printf("[::Resultado da Função em C::]> %f\n",a*b);
		
		return 1;
	
}

