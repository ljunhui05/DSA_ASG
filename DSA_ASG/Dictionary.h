#pragma once
#include<string>
#include<iostream>
#include "Food.h"
using namespace std;

const int MAX_DictSIZE = 50;
typedef string Key;
typedef Food Item;


class Dictionary 
{
private:
	struct Node
	{
		Key	 key;   // search key
		Item item;	// data item
		Node* next;	// pointer pointing to next item with same search key
	};

	Node* items[MAX_DictSIZE];
	int  size;			// number of items in the Dictionary

public:

	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(Key key);

	bool add(Key newKey, Item newItem);

	void remove(Key key);

	Item get(Key key);

	int getLength();

	void print();
};