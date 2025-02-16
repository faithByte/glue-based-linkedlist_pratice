#include "lib.h"

// 2 lists
void	updateNode(_list *list, char c, int n, char c1, int n1){
	_node	*current;
	_data	*data;

	current = list->head;
	while (current){
		data = (_data *)(current - list->offset);
		if ((data->c == c) && (data->n == n)){
			data->c = c1;
			data->n = n1;
			return;
		}
		current = current->next;
	}
}

int	main(){
	_list	*list1 = calloc(1, sizeof(_list));
	_list	*list2 = calloc(1, sizeof(_list));

	list1->offset = 0;
	list2->offset = 1;

	for (int i = 'A'; i <= 'z'; i++){
		if (i <= 'Z')
			insertNode(list1, NULL, i, i);
		else if (i < 'a')
			insertNode(NULL, list2, i, i);
		else
			insertNode(list1, list2, i, i);
	}
	printf("\n-----------------------------------------\n");
	printList(list1);
	printList(list2);
	
	printf("\n-----------------------------------------\n");
	// i only update in list 1 must be updated in list 2
	updateNode(list1, 'a', 'a', '=', '=');
	updateNode(list1, 'A', 'A', '*', '*');
	updateNode(list2, '[', '[', '?', '?');
	printList(list1);
	printList(list2);

	printf("\n-----------------------------------------\n");
	deleteNode(list1, list2, 'x', 'x');
	deleteNode(list1, list2, 'Z', 'Z');
	printList(list1);
	printList(list2);
	
	freeAll(list1, list2);
}