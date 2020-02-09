all: dequedriver

dequedriver: dequedriver.cpp dequeNode.h deque.h deque_empty.h
	g++ dequedriver.cpp -o dequedriver

clean: rm -f dequedriver
