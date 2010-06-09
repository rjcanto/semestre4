#include "CDB_Builder.h"

byte* CDB_field_equalize(char**  field, char * idx){
	if (*idx != 0){
		*field = strndup(idx+1,*idx);
		idx = idx + 1 + *idx;
	}else{
		*field=NULL;
		++idx;
	}
	return idx;
}


