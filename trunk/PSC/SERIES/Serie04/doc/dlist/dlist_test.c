#include <stdlib.h>
#include <assert.h>

#include "dlist.h"

void dlist_test_addThreeNodesThenCount() {
	dlist_t list;
	dnode_t * pnode1, * pnode2, * pn;
	dnode_t node3;
	int count;

	dlist_init(&list);

	pnode1 = (dnode_t *)malloc(sizeof(dnode_t));
	dlist_insertFirst(&list, pnode1);

	pnode2 = (dnode_t *)malloc(sizeof(dnode_t));
	dlist_insertLast(&list, pnode2);

	dlist_insertLast(&list, &node3);

	for (pn = dlist_first(&list), count = 0; pn != &list; pn = pn->next, ++count);

	assert(count == 3);

	free(pnode2);
	free(pnode1);
}

int main() {
	dlist_test_addThreeNodesThenCount();
	return 0;
}

