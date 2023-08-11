#include "Dictionary.h";
#include <iostream>;
#include "string";

using namespace std;

//Lim JunHui (S10242387K)
//Description: Constructor for Dictionary class
Dictionary::Dictionary() {

	for (int i = 0; i <= MAX_DictSIZE-1; i++) {
		items[i] = nullptr;
	}
	size = 0;
}

//Lim JunHui (S10242387K)
//Description: Destructor for Dictionary class
Dictionary::~Dictionary() {
	Node* temp = items[0];

	while (temp != nullptr) {
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

//Lim JunHui (S10242387K)
//Input parameters: FoodID as newKey and Food Object as newItem
//Return value: boolean value
//Description: Function to add a new Food object into the dictionary. It takes the input parameters of
//the FoodID as the key, and the object as the newItem. It returns true if the IDs of the new Food object don't
//match. Else it returns false.
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

//Lim JunHui (S10242387K)
//Input parameters: FoodID as key
//Description: This function removes the Food object with the corresponding key from the dictionary 
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


//Lim JunHui (S10242387K)
//Input parameters: FoodID as key
//Return value: Food object
//Description: This function returns the Food object with the corresponding key from the dictionary.
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

//Lim JunHui (S10242387K)
//Input parameters: FoodID as key
//Return value: Boolean value
//Description: This function goes to the index of the dictionary based on the ID of the Food. If the Key at the 
//index of the dictionary matches the input parameter, it has found the food object and it returns true. Else it
//returns false.
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

//Lim JunHui (S10242387K)
//Return value: Size of the Dictionary
//Description: Function to get the size of the Dictionary
int Dictionary::getLength() {
	return MAX_DictSIZE;
}

//Lim JunHui (S10242387K)
//Description: Function to print all the details of the Food objects in the dictionary
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