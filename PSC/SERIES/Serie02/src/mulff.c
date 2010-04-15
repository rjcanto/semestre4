#include <stdio.h>
int mulff(float *res, float a, float b);

int main(){
	float fp=0;
	float a=-2.5;
	float b=-2.0;

	if (mulff(&fp,a,b))
		printf("::> %f \n",fp);
		printf("**> %f\n",a*b);
		
		return 1;
	
}

