#include <stdio.h>
struct X { int a; char b; };
static struct X x = {10,'A'};
int y = 1;
int main() {
char c=f(y+x.b);
putchar(c); return 0;
}
