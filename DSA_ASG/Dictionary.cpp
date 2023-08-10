#include "Dictionary.h";
#include <iostream>;
#include "string";

using namespace std;


Dictionary::Dictionary() {

	for (int i = 0; i <= MAX_DictSIZE-1; i++) {
		items[i] = nullptr;
	}
	size = 0;
}

Dictionary::~Dictionary() {
	Node* temp = items[0];

	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}


bool Dictionary::add(Key newKey, Item newItem) {
	if (items[newKey] == nullptr) {
		Node* newNode = new Node;
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = nullptr;
		items[newKey] = newNode;
	}

	else { //collision occurred
		Node* current = items[newKey];
		if (current->key == newKey) {
			return false;
		}

		while (current->next != nullptr) {
			current = current->next;
			if (current->key == newKey) {
				return false;
			}
		}

		Node* newNode = new Node;
		newNode->item = newItem;
		newNode->key = newKey;
		newNode->next = nullptr;
		current->next = newNode;
	}

	size++;
	return true;
}

void Dictionary::remove(Key key)
{
	Node* current = items[key];
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (previous == nullptr)
				items[key] = current->next;
			else
				previous->next = current->next;

			delete current;
			size--;
			return;
		}

		previous = current;
		current = current->next;
	}
}

Item Dictionary::get(Key key) {
	Node* current = items[key];

	while (current != nullptr) {
		if (current->key == key) {
			return current->item;
		}

		current = current->next;
	}

	return Item();
}

bool Dictionary::checkFoodExist(Key key) {
	Node* current = items[key];

	while (current != nullptr) {
		if (current->key == key) {
			return true;
		}

		current = current->next;
	}

	return false;
}

int Dictionary::getLength() {
	return MAX_DictSIZE;
}

void Dictionary::print() {
	cout << "+------------------------------------------------------------------+" << endl;
	for (int i = 0; i < MAX_DictSIZE - 1; i++) {
		if (items[i] != NULL) {
			Node* current = items[i];
			cout << current->item.getName();
			cout << "[" << current->item.getID() << "]" << endl;
			cout << "Price: $" << current->item.getPrice() << " |";
			cout << " Quantity " << current->item.getQuantity() << " |";
			cout << " Category: " << current->item.getCategory() << " |";
			cout << " Restaurant: " << current->item.getRestaurant() << endl;
			cout << "+------------------------------------------------------------------+" << endl;
		}
	}
}