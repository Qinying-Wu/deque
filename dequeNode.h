//Qinying Wu
//20783213
//q227wu
//ECE250 P1
//dequeNode class
#include <string>
#include <exception>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
//DequeNode class
class DequeNode
{

public:
	DequeNode* prev; //link to the preivous node
	DequeNode* next; //link to the next node
	int data; //the int data stored in node
	DequeNode(int i, DequeNode* prev, DequeNode* next); //constructor
	~DequeNode(); //destructor
};

//DequeNode* DequeNode::enqueue_front(int i) {
//	//make a new object the head of the deque
//	DequeNode* newObj=new DequeNode(i, nullptr,nullptr,false);
//	//check conditions:
//	//check if the deque has not been initialized with any nodes yet
//	//do not need to check the front of the queue because "this" is the front of the queue
//	if(this->isPlaceholder==true){
//		this->data=i;
//		this->isPlaceholder=false;
//		newObj=this;	
//	}
//	else
//	{
//		//the previous head becomes the next in deque
//		newObj->next=this;
//		this->prev = newObj;
//	}
//
//	cout << "success enqueue front "<<i<< endl;
//	return newObj;
//};
//
////enqueue_back function to add an element to the back of the deque
//void DequeNode::enqueue_back(int i) {
//	//check for if the deque is empty
//	if(this->isPlaceholder==true){
//		this->enqueue_front(i);//if not yet initialized with any nodes, enqueue back is same as enqueue front
//	}
//	else{
//		DequeNode* oldLast=FindLast(); //find the last element in the list
//		DequeNode* newObj=new DequeNode(i,oldLast,nullptr,false);
//		//connect the object back to the end of the doubly linked-list
//		oldLast->next = newObj;
//	}
//	cout<<"success enqueue back "<<i<<endl;
//};
////dequeue_front function to remove an element from the front of the deque
//DequeNode* DequeNode::dequeue_front() {
//	try {
//		if (this->isPlaceholder==true)//if deque is empty, throw exceptioni
//		{
//			throw 1;
//		}
//		DequeNode* newFront=this->next;
//		//only run this if it has not yet reached the last node
//		if(this->next!=nullptr){
//			//deallocate the current node
//			this->next=nullptr;
//			newFront->prev=nullptr;//re-establish the new front
//		}
//		else{
//			newFront=new DequeNode(0,nullptr,nullptr,true);//if all nodes are removed, return a placeholder
//		}
//		cout << "success dequeue front "<<this->data<< endl;
//		return newFront;
//	}
//	catch(int){
//		cout << "failure dequeue front "<<this->data << endl;
//		return this;
//	}
//	
//};
////dequeue_back function to remove an element from the back of the deque 
//DequeNode* DequeNode::dequeue_back() {
//	try {
//		//if the deque is empty, throw exception 
//		//therefore throw exception
//		if (this->isPlaceholder==true)
//		{
//			throw 1;
//		}
//		DequeNode* last=FindLast();
//		DequeNode* headNode=this;
//		//CASE 1: more than 1 node in list (run into if statement)
//		if(last->prev!=nullptr){
//			last->prev->next = nullptr; //prevent dangling pointer
//			last->prev=nullptr;//destruct node
//		}
//		//CASE 2: only 1 node in deque, which is the same as dequeue front
//		else{
//			headNode=dequeue_front();//update the head node
//		}	
//		last->~DequeNode();
//		cout<<"success dequeue back "<<last->data<<endl;
//		return headNode;
//	}
//	catch (int)
//	{
//		cout<<"failure dequeue back"<<endl;
//		return this;
//	}
//
//};
////clear everything from the deque
//DequeNode* DequeNode::clear() {
//	//only clear if the deque is not empty
//	if (this->isPlaceholder==false) {
//		DequeNode* temp=FindLast();
//		while(temp->prev!=nullptr){
//			DequeNode* temp2=nullptr;
//			temp->prev->next=nullptr;
//			temp2=temp->prev;//temporarily stores the next node
//			temp->prev=nullptr;
//			delete temp;
//			temp=temp2;
//		}
//		temp->data=0;
//		temp->isPlaceholder=true;
//		//cout<<"success clear original not empty"<<endl;
//		return new DequeNode(0,nullptr,nullptr,true); //re-establlish the placeholder node
//	}
//	else{
//		//cout<<"success clear original empty"<<endl;
//		return this;
//	}
//};
//Access the first element and
//compare to i, if equal,
//return success, else failure
//string DequeNode::front(int i) {
//	try {
//		//only do this if deque is not empty and data match
//		if (this->isPlaceholder==false&&this->data == i) {
//			return "success front match";
//		}
//		else {
//			throw 1;
//		}
//	}
//	catch (int) {
//		return "failure front match";
//	}
//};
//
////access the last element and compare to i
////if equal, return success, else failure
//string DequeNode::back(int i) {
//	try {
//		//if they equal, return success
//		if (this->isPlaceholder==false&&i == FindLast()->data)
//		{
//			return "success back match";
//		}
//		else
//		{
//			throw 1;
//		}
//	}
//	catch (int) {
//		return "failure back match";
//	}
//	
//};
//
////test if deque is empty
////return success if empty
////failure if not empty
//string DequeNode::empty() {
//	if (!this->isPlaceholder) //not empty return failure
//	{
//		return "failure empty";
//	}
//	else //empty return success
//	{
//		return "success empty";
//	}
//};
//
//
////return the size of the queue
//int DequeNode::size() {
//	if(this->isPlaceholder==true){
//		return 0;//no nodes in the deque
//	}
//	DequeNode* temp=this;
//	int counter=0;
//	while(temp!=nullptr){
//		temp=temp->next;
//		++counter;
//	}
//	return counter;
//};
//
////print all the value in the deque two times
////once forward and once backward
//void DequeNode::print() {
//	if(this->isPlaceholder==true){
//		return;
//	}
//	DequeNode* temp = this;
//	//forward printing
//	while(temp->next!=nullptr){
//		std::cout << temp->data << " ";
//		temp = temp->next; //increment
//	}//stop iterating on the last node
//	
//	cout<<temp->data<<endl; //print out the line break
//	//backward printing
//	while (temp->prev!= nullptr)
//	{
//		std::cout << temp->data << " ";
//		temp = temp->prev; //going back to the head node
//	}
//	cout<<temp->data<<endl;
//	temp=nullptr;
//};



//
////find the last element in the linked list
////returns the pointer address of the last element in the linked list
//DequeNode* DequeNode::FindLast() {
//	DequeNode* newObj = this;
//	while (newObj->next!= nullptr)
//	{
//		newObj = newObj->next;
//
//	}
//	return newObj;
//}
