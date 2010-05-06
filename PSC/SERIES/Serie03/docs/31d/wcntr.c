#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD 64

typedef struct _WInfo {
   int counter;
   char * word;
   struct _WInfo *l,*r;
} WordInfo;

WordInfo *root;

WordInfo * findWord( const char *w ) {
  WordInfo *p=root;
  int res;
  while( p ) {
    if ((res = strcmp(w,p->word))==0) return p;
    p = res>0 ? p->r : p->l ;
  }
  return NULL;
}

WordInfo * insertWord( const char *w ) {
  WordInfo **l=&root;
  WordInfo *p=root;
  int res;
  while( p ) {
    if ((res = strcmp(w,p->word))==0) return p;
    l = res>0 ? &p->r : &p->l ;
    p = *l;
  }
  p = (WordInfo*) malloc( sizeof(WordInfo) );
  p->counter=0;
  p->l = p->r = NULL;
  p->word = (char*) malloc(strlen(w)+1);
  strcpy(p->word,w);
  *l= p;
  return p;
}

char * SEPS = " \",.\n\r\t;():?!";

int readWord( char *w ) {
  int c; char *p = w;
  while ( (c=getchar()) != EOF ) {
    if (strchr(SEPS,c) ) {
      if (p!=w) { *w=0; return 1; }
    }
    else *(w++) = tolower(c);
  }
  return p!=w;
}

void printInfo(WordInfo *r) {
  if (!r) return;
  printInfo(r->l);
  printf("%s -> %d\n",r->word,r->counter);
  printInfo(r->r);
}

void freeTree(WordInfo *r) {
  if (!r) return;
  freeTree(r->l);
  freeTree(r->r);
  free(r->word);
  free(r);  
}


int main(int argc, char* argv[]) {
  char w[MAX_WORD];
  WordInfo *wp;
  
  while( readWord(w) ) {
    wp = findWord(w);
    if (!wp) wp = insertWord(w);
    wp->counter++;
  }
  printInfo(root);
  freeTree(root);
  return 0;
}













