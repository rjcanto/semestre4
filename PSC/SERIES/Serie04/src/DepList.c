void DepList_deleteNode(DepList* list){
		while (!isEmpty_LL(list)) {
			if (list->acronimo != NULL){
				free(list->acronimo);
				list->acronimo=NULL;
			}
			DepList_deleteNode((DepList*)removeFirst_LL(list));
		}
		list = NULL;	
}
