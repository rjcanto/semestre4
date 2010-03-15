

struct Node{
	char *descriptor;
	struct Node *ifTrue;
	struct Node *ifFalse;
};

struct guess_Vtable{
	(void   (*)      ()) destroy,
	(void   (*)      ()) add,
	(void   (*)		 ()) remove
}



void guess_ctor(){}
void guess_init(){}


void guess_add(){}
void guess_remove(){}


void guess_dtor(){}


struct Guess{
	guess_Vtable *vptr;
	Node head;
	Node node;
}
guess_Vtable guess_vptr={
	&guess_dtor,
	&guess_add,
	&guess_remove	
}

