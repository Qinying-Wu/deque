//Qinying Wu
//20783213
//q227wu
//ECE250 P1
//dequedriver.cpp
#include <cmath>
#include "deque.h"
#include "deque_empty.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

//this is the main function, entry point of the program
int main()
{
	string input = "";
	//initialize dummy object
	Deque dd(nullptr, nullptr, 0);
	//DequeNode* dd = new DequeNode(0,nullptr,nullptr,true);
	while (getline(cin, input))
	{
		int index = input.find(' '); //find the separation between the command and parameter (if any)
		//for commands with parameters
		//?will commands like print, empty, front have space before or after?
		if (index != -1)
		{
			string command = input.substr(0, index);
			int i = std::stoi(input.substr(index + 1, input.length()));
			if (command == "enqueue_front")
			{
				//assign the head with the base address of the enqueued address
				dd.enqueue_front(i);
			}
			else if (command == "enqueue_back")
			{
				dd.enqueue_back(i);
			}
			else if (command == "front")
			{
				dd.front(i);

			}
			else if (command == "back")
			{
				dd.back(i);
			}
			else if (command == "size") {
				dd.size();
			}
		}
		//for commands without parameter
		else {
			if (input == "dequeue_front") {
				dd.dequeue_front();
			}
			else if (input == "dequeue_back") {
				dd.dequeue_back();
			}
			else if (input == "clear") {
				dd.clear();
				cout<<"success"<<endl;
			}
			else if (input == "empty") {
				dd.empty();
			}
			else if (input == "size") {
				dd.size();
			}
			else if (input == "print") {
				dd.print();
			}
		}
	}
	return 0;
}
//empty constructor for the exception class
deque_empty::deque_empty(){}

//empty destructor for the exception class
deque_empty::~deque_empty(){}

//constructor for a DequeNode object with data initialization
//int i is the data to be stored in the node
//prev is the base address of the previous node
//next is the base address of the next node
DequeNode::DequeNode(int i, DequeNode* prev, DequeNode* next) {
	data = i;
	this->prev = prev;
	this->next = next;
}

//destructor for a DequeNode object
DequeNode::~DequeNode() {
	if (this->prev != nullptr) {
		this->prev->next = nullptr;
		this->prev = nullptr;
	}
	if (this->next != nullptr) {
		this->next->prev = nullptr;
		this->next = nullptr;
	}


}
//constructor for the Deque class
//front is the head of the deque
//back is the last element of the deque
//size is how many nodes contained in the deque
Deque::Deque(DequeNode* front, DequeNode* back, int size) {
	FrontNode = front;
	BackNode = back;
	DequeSize = size;
}
//Deque class destructor, erases every node in the deque stored in memory
Deque::~Deque() {
	this->clear();
}

//enqueue_front function to add an element to the front of the deque
//int i is the integer data to be stored in the node
void Deque::enqueue_front(int i) {
	//make a new object the head of the deque
	DequeNode* newObj = new DequeNode(i, nullptr, nullptr);

	//check conditions:
	//check if the deque has been initialized with any nodes yet
	if (this->FrontNode == nullptr && this->BackNode == nullptr) {
		this->FrontNode = newObj;
		this->BackNode = newObj;
	}
	//only one node in deque
	else if (this->FrontNode == this->BackNode)
	{
		this->FrontNode = newObj;
		newObj->next = this->BackNode;
		this->BackNode->prev = newObj;
	}
	//more than one node in deque
	else
	{
		this->FrontNode->prev = newObj;
		newObj->next = this->FrontNode;
		this->FrontNode = newObj;
	}
	++DequeSize;//increment the size
	cout << "success" << endl;
}

//add an element to the back of the deque
//int i is the data to be stored into the node
void Deque::enqueue_back(int i) {
	//make a new object the head of the deque
	DequeNode* newObj = new DequeNode(i, nullptr, nullptr);

	//check conditions:
	//check if the deque has been initialized with any nodes yet
	if (this->FrontNode == this->BackNode)
	{
		//no element in deque
		if (this->FrontNode == nullptr && this->BackNode==nullptr) {
			this->FrontNode = newObj;
			this->BackNode = newObj;
		}
		//one element in deque
		else {
			this->FrontNode->next = newObj;
			this->BackNode = newObj;
			this->BackNode->prev = this->FrontNode;
		}
		
	}
	//more than one node in deque
	else
	{
		newObj->prev = this->BackNode;
		this->BackNode->next = newObj;
		this->BackNode = newObj;
	}
	++DequeSize;//increment the size
	cout << "success" << endl;
}

//remove an element from the front of the deque
void Deque::dequeue_front() {
	try {
		//same front and tail nodes
		if (this->FrontNode == this->BackNode)
		{
			//if empty, then throw exception
			if (this->FrontNode == nullptr && this->BackNode == nullptr)
			{
				throw deque_empty();
			}
			//only 1 element in deque
			else {
				this->FrontNode->~DequeNode();
				delete this->FrontNode;
				this->FrontNode=nullptr;
				this->BackNode=nullptr;
			}
		}
		else {
			//temporarily store the next node of the front
			DequeNode* temp = this->FrontNode->next;
			this->FrontNode->~DequeNode();
			delete this->FrontNode;
			this->FrontNode = temp;
			//temp = nullptr; //deallocate to nullptr when finished
		}
		--DequeSize;//decrement the size
		cout << "success" << endl;
	}
	catch (deque_empty) {
		cout << "failure" << endl;
	}

};
//dequeue_back function to remove an element from the back of the deque 
void Deque::dequeue_back() {
	try {
		//if empty, then throw exception
		if (this->FrontNode == nullptr && this->BackNode == nullptr)
		{
			throw deque_empty();
		}
		//only 1 element in deque
		else if (this->FrontNode == this->BackNode && this->FrontNode != nullptr)
		{
			this->BackNode->~DequeNode(); //means clear everything
			delete this->BackNode;
			this->FrontNode=nullptr;
			this->BackNode=nullptr;
		}
		else {
			//temporarily store the next node of the front
			DequeNode* temp = this->BackNode->prev;
			this->BackNode->~DequeNode(); //destructor
			delete this->BackNode;
			this->BackNode = temp;
			//temp = nullptr; //deallocate to nullptr when finished
		}
		--DequeSize;//decrement the size
		cout << "success" << endl;
	}
	catch (deque_empty) {
		cout << "failure" << endl;
	}

};

//clear function to remove everything from the deque
void Deque::clear() {
	//only run this if deque is not empty
	if (this->FrontNode == this->BackNode) {
		//no element in deque then do not need to clear
		if (this->FrontNode == nullptr&&DequeSize==0)
		{
			return;
		}
		//only one element in deque
		else {
			this->FrontNode->~DequeNode();
			delete this->FrontNode;
			this->FrontNode = nullptr;
			this->BackNode = nullptr;
			--DequeSize;
		}
	}
	else {
		DequeNode* temp = this->FrontNode;
		while (temp != nullptr)//run this while not yet at the back of the deque
		{
			DequeNode* temp2=temp->next;
			temp->~DequeNode();//destroy the previous node
			delete temp;
			temp = temp2;
			--DequeSize;
		}
		//reached the back of the deque
		this->FrontNode = nullptr;
		this->BackNode = nullptr;
	}
}
//checks if the data of the first element in the deque matches the parameter given
//if it matches given that the deque is not empty, it outputs success
//otherwise it outputs failure
//int i is the integer value to be compared with the node data
void Deque::front(int i) {
	try{
		if (this->FrontNode != nullptr && this->FrontNode->data == i) {
			cout << "success" << endl;
		}
		else{
			throw deque_empty();
		}
	}
	catch(deque_empty) {
		cout << "failure" << endl;
	}
};
//checks if the data of the last element in the deque matches the parameter given
//output success if the data matches given that the deque is non-empty
//other wise output failure
//int i is the integer value to be compared with the node data
void Deque::back(int i) {
	try{
		if (this->BackNode != nullptr && this->BackNode->data == i) {
			cout << "success" << endl;
		}
		else {
			throw deque_empty();
		}
	}
	catch(deque_empty){
			cout<<"failure"<<endl;
	}
}
//determine if the deque is empty or not
//output success if deque contains no nodes
//otherwise an exception is thrown and output failure
void Deque::empty() {
	//only print success if both front and back are nullptrs and size is 0
	try{
		if (this->FrontNode == nullptr && this->BackNode == nullptr && this->DequeSize == 0) {
			cout << "success"<<endl;
		}
		//otherwise throw an exception
		else{
			throw deque_empty();
		}
	}
	//not empty
	catch(deque_empty) {
		cout << "failure" << endl;
	}
}

//print out the size of the deque (total number of nodes contained)
void Deque::size() {
	cout << "size is " << this->DequeSize << endl;
}
//print the data stored in the nodes of the deque starting from the first element to the last element
//then from the back up to the front
void Deque::print() {
	if(this->FrontNode==nullptr&&this->BackNode==nullptr&&this->DequeSize==0){return;}
	DequeNode* temp = this->FrontNode; //temporary variable to iterate through the deque
	//forward printing
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl; //switch to a new line after finished printing
	//backward printing
	temp = this->BackNode;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}
