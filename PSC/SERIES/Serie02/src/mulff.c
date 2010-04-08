#include <stdio.h>
int mulff(float *res, float a, float b);

int main(){
	float fp=0;
	
	if (mulff(&fp,1.0,2.5))
		printf("::> %f \n",fp);
		
		return 1;
	
}

