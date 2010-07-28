typedef unsigned int X;
X x = 2;
extern int y;
static int * g(int b) {
int res=1;
res+=b+y; return &res;
}
int f(int a) { return ++a; }
