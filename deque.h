//Qinying Wu
//20783213
//q227wu
//ECE250 P1
//Deque linked list class
#include <string>
#include "dequeNode.h"
using std::string;
class Deque {
public:
	DequeNode* FrontNode;	//the first element of the deque
	DequeNode* BackNode;	//the last element of the deque
	int DequeSize;			//the total number of nodes in the deque
	void enqueue_front(int i);	//add to the deque at the front
	void enqueue_back(int i);	//add to the deque at the back
	void dequeue_front();		//remove from the deque at the front
	void dequeue_back();		//remove from the deque at the back
	void clear();				//removed every node from the deque
	void front(int i);			//check if the first element stores the same data as i
	void back(int i);			//check if the last element stores the same data as i
	void empty();				//check if the deque contains any node or not
	void size();				//outputs the total number of nodes in the deque
	void print();				//print the data stored in every node of the deque
	Deque(DequeNode* front, DequeNode* back,int size);		//constructor
	~Deque();		//destructor
};
