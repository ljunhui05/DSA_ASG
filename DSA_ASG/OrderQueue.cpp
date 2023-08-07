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

bool Queue::enqueue(ItemType item) {
	struct Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (frontNode == nullptr) {
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

bool Queue::dequeue(ItemType& item) {
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


void Queue::getFront(ItemType& item) {
	if (frontNode != nullptr) {
		item = frontNode->item;
	}
}

bool Queue::isEmpty() {
	if (frontNode == nullptr) {
		return true;
	}

	else {
		return false;
	}
}

void Queue::displayItems() {
	Node* temp = frontNode;
	while (temp != nullptr) {
		Node* next = temp->next;
		temp->item.displayOrderDetails();
		temp = next;
	}
}