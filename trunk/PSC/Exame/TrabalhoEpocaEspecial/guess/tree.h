#ifndef _TREE
#define _TREE
typedef struct TreeNode GuessTree;
struct TreeNode{
	int			key;
	char		*descriptor;
	GuessTree 	*left;/*if true*/
	GuessTree	*right;/*if false*/
};
GuessTree* searchMin(GuessTree* this );
GuessTree* searchTree(GuessTree* this, int key);
GuessTree* removeNode(GuessTree* this, int key);
GuessTree* addNode(GuessTree* this, int key,char* descriptor);
void destroyTree(GuessTree* node);
#endif
