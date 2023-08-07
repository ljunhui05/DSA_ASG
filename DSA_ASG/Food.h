#pragma once
#include <string>
#include <iostream>
using namespace std;

class Food 
{
private:
	int FoodID;
	string FoodName;
	string Category;
	string Restaurant;
	int Quantity;

public:

	Food();

	//Constructor
	Food(int FoodID, string FoodName, string Category, string Restaurant, int quantity);

	string getName();

	void printFoodDetails();
};