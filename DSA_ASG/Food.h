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
	int Price;
	int Quantity;

public:

	Food();

	//Constructor
	Food(int FoodID, string FoodName, string Category, string Restaurant, int Price ,int Quantity);

	int getID();

	string getName();
	
	string getCategory();

	string getRestaurant();

	int getPrice();

	int getQuantity();

	void printFoodDetails();
};