#include <string>
#include <iostream>
using namespace std;
#include "HashTable.h"

HashTable::HashTable() {

	for (int i = 0; i <= MAX_SIZE; i++) {
		items[i] = nullptr;
	}
	size = 0;
}

HashTable::~HashTable() {
	Node* temp = items[0];

	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

int HashTable::hash(KeyType key) {
	int sum = 0;
	for (char ch : key)
		sum += ch;
	return sum % MAX_SIZE;
}

bool HashTable::add(KeyType newKey, ItemType newItem) {
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

void HashTable::remove(KeyType key)
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

ItemType HashTable::get(KeyType key) {
	int index = hash(key);
	Node* current = items[index];

	while (current != nullptr) {
		if (current->key == key) {
			return current->item;
		}

		current = current->next;
	}

	return ItemType();
}

int HashTable::getLength() {
	return MAX_SIZE;
}