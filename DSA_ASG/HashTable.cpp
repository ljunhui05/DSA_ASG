//-----------------------------//
// Lim JunHui (S10242387K)     //
//-----------------------------//
#include <string>
#include <iostream>
using namespace std;
#include "HashTable.h"

//Constructor of HashTable
HashTable::HashTable() {

	for (int i = 0; i <= MAX_HashSIZE-1; i++) {
		items[i] = nullptr;
	}
	size = 0;
}

//Destructor of HashTable
HashTable::~HashTable() {
	Node* temp = items[0];

	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

//Input parameters: member username as key
//Return value: returns an integer which is the index in the hashtable that the item should be inserted at
//Description: Hash function for HashTable, which takes the input parameters of the member username
int HashTable::hash(KeyType key) {
	int sum = 0;
	for (char ch : key)
		sum += ch;
	return sum % MAX_HashSIZE;
}

//Input parameters: member username as newKey and Member object as newItem
//Return value: boolean value
//Description: Function to add a new Member object into the hashtable. It takes the input parameters of
//the member's user name as the key, and the object as the Item. If the username of a member in the hashtable
//is the same as the member being added, then it returns false. Else it returns true.
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
//Input parameters: member username as key
// Description: Function to remove the member object from the hashtable. It takes in the member's 
// username as a input parameter which is used by the hash function, and removes the object at the index that 
//the hash function returns.
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

//Input parameters: member username as key
//Return value: Member Object
//Description: Function to get the member object at a certain index, which is derived by using the 
//hash function and the input parameter of the member's username.
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

//Input parameters: member username as key
//Return value: boolean value
//Description: Function to check if the username exists in the hashtable and returns true if it does. 
//If it does not it returns false
bool HashTable::checkMemberExist(KeyType key) {
	int index = hash(key);
	Node* current = items[index];

	while (current != nullptr) {
		if (current->key == key) {
			return true;
		}

		current = current->next;
	}

	return false;
}

//Input parameters: member username as key and member password as pass
//Return value: boolean value
//Description: Function to check if the password in the input parameters matches the password given in the input
//parameters. If it does, it returns true, else it returns false.
bool HashTable::checkPass(KeyType key, string pass) {
	int index = hash(key);
	Node* current = items[index];

	while (current != nullptr) {
		if (current->item.getPass() == pass) {
			return true;
		}

		current = current->next;
	}

	return false;
}

//Description: Function to print out all the items in the hashtable
void HashTable::print() {
	for (int i = 0; i < MAX_HashSIZE - 1; i++) {
		if (items[i] != NULL) {
			Node* current = items[i];
			cout << items[i]->item.getName()<< endl;
		}
	}
}

//Return value: size of the hashtable
//Description: Function to get the size of the hashtable
int HashTable::getLength() {
	return MAX_HashSIZE;
}