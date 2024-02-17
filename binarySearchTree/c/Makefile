C_FLAGS := -c -g -Wextra -Wall -fmax-errors=5 -pedantic 

testbst: main.o test.o bst.o 
	gcc -o testbst main.o bst.o test.o

main.o:	main.c test.h
	gcc ${C_FLAGS} main.c 

test.o: test.c test.h bst.h
	gcc ${C_FLAGS} test.c 

bst.o: bst.c bst.h
	gcc ${C_FLAGS} bst.c 

.PHONY: clean 
clean:
	rm *.o testbst *.txt