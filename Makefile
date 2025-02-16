# sudo sysctl -w vm.mmap_rnd_bits=28

all: run

multi:
	@gcc -g -fsanitize=address mmain.c functions.c -o MultiGluedDoublyLinkedList
	@./MultiGluedDoublyLinkedList

run:
	@gcc -g -fsanitize=address main.c -o GluedDoublyLinkedList
	@./GluedDoublyLinkedList
