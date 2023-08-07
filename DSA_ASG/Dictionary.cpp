#include "Dictionary.h";
#include <iostream>;
#include "string";

using namespace std;


Dictionary::Dictionary() {

	for (int i = 0; i <= MAX_SIZE; i++) {
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

int Dictionary::hash(Key key) {
	int sum = 0;
	for (char ch : key)
		sum += ch;
	return sum % MAX_SIZE;
}

bool Dictionary::add(Key newKey, Item newItem) {
	int index = hash(newKey);
	if (items[index] == nullptr) {
		Node* newNode = new Node;
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = nullptr;
		items[index] = newNode;
	}

	else { //collision occurred
		Node* current = items[index];
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
	int index = hash(key);
	Node* current = items[index];
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (previous == nullptr)
				items[index] = current->next;
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
	int index = hash(key);
	Node* current = items[index];

	while (current != nullptr) {
		if (current->key == key) {
			return current->item;
		}

		current = current->next;
	}

	return Item();
}

int Dictionary::getLength() {
	return MAX_SIZE;
}

void Dictionary::print() {
	for (int i = 0; i < MAX_SIZE - 1; i++) {
		if (items[i] != NULL) {
			Node* current = items[i];
			cout << " Food: " << current->item.getName() << endl;
			cout << " Category: " << current->item.getCategory() << endl;
		}
	}
}