# sudo sysctl -w vm.mmap_rnd_bits=28

all: exec run

exec:
	@gcc -g -fsanitize=address main.c -o GluedDoublyLinkedList

run:
	@./GluedDoublyLinkedList
