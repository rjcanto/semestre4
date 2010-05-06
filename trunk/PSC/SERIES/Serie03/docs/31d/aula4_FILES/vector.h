
struct _vector {
  int len;	 /* Número de elementos usados */
  int *vec;  /* Ponteiro para array com 'len' elementos */
};
 
typedef struct _vector Vector; 

void init_vector(Vector *v, int size, int *array);
int length_vector(Vector *v);

int elem_vector(Vector *v, int idx, int *dest);
void elem_vector_nochk(Vector *v, int idx, int *dest);

int * start_vector(Vector *v);

