#include <iostream>;
#include <string>;
using namespace std;
#include "OrderQueue.h";

//Lim JunHui (S10242387K)
//Description: Constructor for Queue class
Queue::Queue() {
	frontNode = nullptr;
	backNode = nullptr;
}

//Lim JunHui (S10242387K) 
//Description: Destructor for Queue class
Queue::~Queue() {
	Node* temp = frontNode;
	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}

}

//Lim JunHui (S10242387K)
//Input parameters: Order object as item
//Return value: boolean value
//Description: This function enqueues the a order object to the back of the Queue and returns true 
//once it has successfully done so
bool Queue::enqueue(OrderItem item) {
	struct Node* newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;

	if (isEmpty()) {
		frontNode = newNode;
	}

	else {
		backNode->next = newNode;
		
	}
	backNode = newNode;
	return true;
}

//Lim JunHui (S10242387K)
//Return value: boolean value
//Description: This function dequeues the first Order object in the Queue and returns true once it has done so
bool Queue::dequeue() {
	if (frontNode == backNode) {
		frontNode = nullptr;
		backNode = nullptr;
	}
	else {
		Node* temp = frontNode;
		frontNode = frontNode->next;
		temp->next = nullptr;
		delete temp;
	}
	return true;
}

//Lim JunHui (S10242387K)
//Input parameters: A referenced Order object as item
//Return value: boolean value
//Description: This function dequeues the first Order object in the Queue and returns true once it has done so.
//This function also assigns the value of the first order object in the Queue to a referenced Order object
//called item
bool Queue::dequeue(OrderItem& item) {
	if (frontNode == backNode) {
		item = frontNode->item;
		frontNode = nullptr;
		backNode = nullptr;
	}
	else {
		Node* temp = frontNode;
		item = temp->item;
		frontNode = frontNode->next;
		temp->next = nullptr;
		delete temp;
	}
	return true;
}

//Lim JunHui (S10242387K)
//Input parameters: A referenced Order object as item
//Description: This function assigns the value of the first Order object in the queue to a referenced 
//Order object called item 
void Queue::getFront(OrderItem& item) {
	if (frontNode != nullptr) {
		item = frontNode->item;
	}
}

//Lim JunHui (S10242387K)
//Input parameters:Member object as member
//Return value: Returns a list of Order objects
//Description: This function loops through the Queue to find the Order objects that have the name of the member that
//is the input parameter. If the names match, it is added into a list of Order objects called memberOrderList. Once
//the function has reached the end of the Queue, it returns memberOrderList
List<Order> Queue::getMemberOrder(Member member) {
	List<Order> memberOrderList;
	Node* temp = frontNode;
	while (temp != nullptr) {
		if (temp->item.getMemberDetails().getName() == member.getName()) 
		{
			memberOrderList.add(temp->item);
		}

		temp = temp->next;
	}

	return memberOrderList;
}

//Lim JunHui (S10242387K)
//Return value: boolean value
//Description: This function checks if the Queue is empty. It returns true if it is. Else it returns false
bool Queue::isEmpty() {
	if (frontNode == nullptr) {
		return true;
	}

	else {
		return false;
	}
}

//Lim JunHui (S10242387K)
//Return value: Length of the Queue as int
//Description: This function loops through the Queue and adds 1 to a counter called len whenever it moves to the
//next item in the Queue. len is then returned.
int Queue::getLength() {
	int len = 0;
	Node* temp = backNode;
	while (temp != nullptr) {
		Node* next = temp->next;
		len += 1;
		temp = next;
	}

	return len;
}

Queue::Node* Queue::getFrontNode() 
{
	return frontNode;
}
