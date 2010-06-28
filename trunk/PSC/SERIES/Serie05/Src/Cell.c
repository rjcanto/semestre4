#include "Cell.h"
enum status {NONE='*', FLAG='X', VIEW=' '};
typedef enum status Status;
typedef struct Tstat{
	Status view;	
}Stat;

Stat stat;

	char getView(){
		puts ("Method not yet implemented."); return 0;
	}
	void touch(){
		puts("Method not yet implemented.");
	}
	boolean isBomb(){return false;}

	void print(){
		printf("%c",(stat.view == VIEW)? getView(): stat.view);
	}
	const boolean isShown(){return stat.view == VIEW;}
	const boolean isFlagged(){return stat.view == FLAG;}
	void show(){stat.view= VIEW;}
	void toggleFlag(){
		if ( stat.view == FLAG ) stat.view=NONE;
		else
		if ( stat.view == NONE ) stat.view=FLAG;
	}
	void Cell_init(){
		stat.view=NONE;
	}
