#include "stdio.h"

unsigned int strspn(const char* str, const char* strcharset);
const char* longest_match(const char* vstr[],unsigned int nstr, const char* strCharset);
char* struprcnt(char* str, unsigned int* pcnt);



struct  StrToConvert{
	unsigned int nconverted;
	char*	str;
};

unsigned int ConvertAllStrs(struct StrToConvert toConv[], unsigned int nconvs, char* (*strconvf)(char*, unsigned int*)) ;
struct StrToConvert toConv[4]={{0,"acabei"},{0,"abacate"},{0,"abaabacateessa"},{0,"abaabACateessa"}};

typedef struct _stay{
	char* name;
	int		floor;
	int		room;
}Stay;

Stay* stays[4][10];

Stay* stay(int f, int r);
int main(){
	/*const char* str[]={"acabei","abacate","abaabacateessa"};*/
	
	
	
	
	
	printf(">> [%d]\n",(int) stay(4,10));
	

return 1;	
}
