all : min_heap.c
	gcc -o min_heap min_heap.c
clean : 
	rm -rf min_heap