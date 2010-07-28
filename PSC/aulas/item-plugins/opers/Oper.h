#include <dlfcn.h>

struct _Oper;
typedef struct _Oper Oper;

typedef char * (*nameFx)(Oper * this);
typedef void   (*insertFx)(Oper * this, float);
typedef float  (*resultFx)(Oper * this);
typedef void   (*resetFx)(Oper * this);
typedef void   (*destroyFx)(Oper * this);

typedef struct {
  destroyFx destroy;
  nameFx name;
  insertFx insert;
  resultFx result;
  resetFx reset;
} VtableOper;


struct _Oper {
  VtableOper *vtbl;
  void * h;
  /* .... */
};

Oper * loadOper(char * opName);
void destroyOper(Oper * op);

#define pcall(o,fx) (o)->vtbl->fx(o) 
#define pcall1(o,fx,p) (o)->vtbl->fx(o,p) 

/* JAVA 
public interface Oper {
  String name();
  void insert(float val);
  float result();
  void reset();
}
*/
