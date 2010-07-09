#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H
#include "newtypes.h"

typedef struct game_t{
	void 	(*newGame)	();
	boolean	(*isSolved)	();
	void 	(*touch)	(int, int);
	void 	(*showAll)	();
	void 	(*flag)		(int, int);
	void 	(*exit)		();
}Game_Methods;
#endif
