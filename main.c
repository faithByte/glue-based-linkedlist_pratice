#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct node {
	struct node *previous;
	struct node *next;
} _node;

typedef struct list {
	_node	*head;
	_node	*last;
} _list;

typedef struct type {
	_node	ptr;
	char	c;
	size_t	n;
	// other stuffs
} _type;

void	insertNode(_list *list, char c, size_t n){
	_type	*nodeData;

	nodeData = malloc(sizeof(_type));
	nodeData->c = c;
	nodeData->n = n;
	nodeData->ptr.next = NULL;

	if (!list->head)
		list->head = &nodeData->ptr;
	else
		list->last->next = &nodeData->ptr;

	nodeData->ptr.previous = list->last;	// if !list->head - list->last == NULL
	list->last = &nodeData->ptr;
}

void	removeNode(_list *list, char c, int n){
	_node	*current;
	_type	*data;

	current = list->head;
	while (current){
		data = (_type *)current;
		if ((data->c == c) && (data->n == n)){
			if (current == list->head){
				list->head = current->next;
				if (list->head)
					list->head->previous = NULL;
			}
			else
				current->previous->next = current->next;
			if (current == list->last){
				list->last = current->previous;
				if (list->last)
					list->last->next = NULL;
			}
			else
				current->next->previous = current->previous;
			free(data);
			return;
		}
		current = current->next;
	}
	
}

void	printList(_list *list){
	_node *current;
	_type *ptr;

	current = list->head;
	while (current){
		ptr = (_type *)current;
		// printf("%ld:%c, ", ptr->n, ptr->c);
		printf("%c", ptr->c);
		current = current->next;
	}
	printf("\n");
	
}

void	freeList(_list *list){
	_node *current;
	_type *ptr;

	current = list->head;
	while (current){
		ptr = (_type *)current;
		current = current->next;
		free(ptr);
	}
	free(list);
}

int	main(){
	_list	*list = calloc(1, sizeof(_list));
	for (int i = 'A'; i <= 'z'; i++)
		insertNode(list, i, i);
	printList(list);

	for (int i = 'A'; i <= 'z'; i++)
		removeNode(list, i, i);
	printList(list);

	printf("--------------------------------------\n");
	for (int i = 'A'; i <= 'z'; i++)
		insertNode(list, i, i);
	printList(list);
	removeNode(list, 'a', 'a');
	printList(list);
	removeNode(list, '[', '[');
	printList(list);
	removeNode(list, 'A', 'A');
	printList(list);
	removeNode(list, 'z', 'z');
	printList(list);
	freeList(list);
}