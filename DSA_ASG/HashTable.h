#pragma once
#include <string>
#include <iostream>
#include "Member.h"
using namespace std;

const int MAX_HashSIZE = 100;
typedef string KeyType;
typedef Member ItemType;


class HashTable
{
private:
	struct Node
	{
		KeyType	 key;   // search key
		ItemType item;	// data item
		Node* next;	// pointer pointing to next item with same search key
	};

	Node* items[MAX_HashSIZE];
	int  size;			// number of items in the Dictionary

public:

	// constructor
	HashTable();

	// destructor
	~HashTable();

	int hash(KeyType key);

	bool add (KeyType newKey, ItemType newItem);

	void remove(KeyType key);

	ItemType get(KeyType key);

	bool checkExist(KeyType key);

	int getLength();


};
