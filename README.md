# Glue Based Linked List

A **glued doubly linked list** is essentially a special type of linked list where each node not only connects to the next and previous nodes (like in a regular doubly linked list), but also has an additional "glue" that connects it to another part of the list or even a different list entirely.

## Traditional Doubly Linked List
<p align="center">
  <img alt="traditional doubly linked list" src="https://github.com/faithByte/glued-doubly-linkedlist_pratice/blob/main/img/traditional.png">
</p>

## Glued Doubly Linked List
<p align="center">
  <img alt="glued doubly linked list" src="https://github.com/faithByte/glued-doubly-linkedlist_pratice/blob/main/img/glued.png">
</p>

## Multiple Traditional Doubly Linked List
<p align="center">
  <img alt="traditional doubly linked lists" src="https://github.com/faithByte/glued-doubly-linkedlist_pratice/blob/main/img/multi_trad.png" style="width: 100%; height: auto;">
</p>

## Multiple Glued Doubly Linked List
<p align="center">
  <img alt="glued doubly linked lists" src="https://github.com/faithByte/glued-doubly-linkedlist_pratice/blob/main/img/multi_glued.png" style="width: 100%; height: auto;">
</p>

In a traditional doubly linked list, if a node appears in multiple lists, you must traverse each list individually to find and remove the node. In contrast, a glued doubly linked list allows you to traverse the node once and use the "glue" pointers to directly access and remove the node from all lists at once. This makes the glued structure faster when the node is part of multiple lists.
