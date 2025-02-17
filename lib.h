#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	struct node *previous;
	struct node *next;
} _node;

typedef struct list {
	_node	*head;
	_node	*last;
	int		offset;		// node index in _data ptr[offset]
} _list;

typedef struct data {
	_node	ptr[2];		// ptr[n] n is the number of lists  // we can use *ptr to make it dynamic to each node
	// the data stored in the list
	char	c;
	size_t	n;
	// other stuffs
} _data;

void	printList(_list *list);
void	insertNode(_list *list1, _list *list2, char c, size_t n);
void	updateList(_list *list, _data *nodeData);
void	popNode(_list *list, _node *current);
void	deleteNode(_list *list1, _list *list2, char c, int n);
void	freeAll(_list *list1, _list *list2);
void	updateNode(_list *list, char c, int n, char c1, int n1);