#include <iostream>;
#include <string>;
using namespace std;
#include "OrderQueue.h";

Queue::Queue() {
	frontNode = nullptr;
	backNode = nullptr;
}

Queue::~Queue() {
	Node* temp = frontNode;
	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}

}

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


void Queue::getFront(OrderItem& item) {
	if (frontNode != nullptr) {
		item = frontNode->item;
	}
}

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

bool Queue::isEmpty() {
	if (frontNode == nullptr) {
		return true;
	}

	else {
		return false;
	}
}

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