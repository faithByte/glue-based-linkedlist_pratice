#include "lib.h"

// print
void	printList(_list *list){
	_node *current;
	_data *ptr;

	current = list->head;
	while (current){
		ptr = (_data *)(current - list->offset);
		printf("%c", ptr->c);
		current = current->next;
	}
	printf("\n");
}

// insert
void	insertNode(_list *list1, _list *list2, char c, size_t n){
	_data	*nodeData;

	nodeData = calloc(1, sizeof(_data));
	nodeData->c = c;
	nodeData->n = n;

	if (list1)
		updateList(list1, nodeData);
	if (list2)
		updateList(list2, nodeData);	

}

// update
void	updateList(_list *list, _data *nodeData){
	
	(nodeData->ptr[list->offset]).next = NULL;
	if (!list->head)
		list->head = &(nodeData->ptr[list->offset]);
	else
		list->last->next = &(nodeData->ptr[list->offset]);

	(nodeData->ptr[list->offset]).previous = list->last;
	list->last = &(nodeData->ptr[list->offset]);
}

// pop / delete / free
void	popNode(_list *list, _node *current){

	if (!current)
		return ;
	if (current == list->head){
		list->head = current->next;
		if (list->head)
			list->head->previous = NULL;
	}
	else if (current->previous)
		current->previous->next = current->next;
	if (current == list->last){
		list->last = current->previous;
		if (list->last)
			list->last->next = NULL;
	}
	else if (current->next)
		current->next->previous = current->previous;
}

void	deleteNode(_list *list1, _list *list2, char c, int n){
	_node	*current;
	_data	*data;

	current = list1->head;
	while (current){
		data = (_data *)current;
		if ((data->c == c) && (data->n == n)){
			popNode(list1, &(data->ptr[0]));
			popNode(list2, &(data->ptr[1]));
			free(data);
			return;
		}
		current = current->next;
	}
}

void	freeAll(_list *list1, _list *list2){
	_node	*current;
	_node	*tmp;
	_data	*data;

	current = list1->head;
	while (current){
		tmp = current->next;
		data = (_data *)(current - list1->offset);
		// popNode(list, &(data->ptr[0]));
		popNode(list2, &(data->ptr[list2->offset])); // remove it from list2 before removing
		free(data);
		current = tmp;
	}

	current = list2->head;
	while (current){
		tmp = current->next;
		free((_data *)(current - list2->offset));
		current = tmp;
	}

	free(list1);
	free(list2);
}