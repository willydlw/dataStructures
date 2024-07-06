C_FLAGS := -c -g -Wextra -Wall -fmax-errors=5 -pedantic 

testbst: main.o test.o bst.o 
	g++ -o testbs++t main.o bst.o test.o

main.o:	main.cpp test.h
	g++ ${C_FLAGS} main.cpp 

test.o: test.cpp test.h bst.h
	g++ ${C_FLAGS} test.cpp 

bst.o: bst.cpp bst.h
	g++ ${C_FLAGS} bst.cpp

.PHONY: clean 
clean:
	rm *.o testbst *.txt