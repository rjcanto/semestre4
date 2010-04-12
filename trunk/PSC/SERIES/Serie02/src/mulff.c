#include <stdio.h>
int mulff(float *res, float a, float b);

int main(){
	float fp=0;
	
	if (mulff(&fp,-1024.75,-2048.25))
		printf("::> %f \n",fp);
		
		return 1;
	
}

