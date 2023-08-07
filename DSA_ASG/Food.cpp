#include <string>
#include <iostream>
using namespace std;
#include "Food.h"

Food::Food() 
{

}

Food::Food(int foodID, string foodName, string category, string restaurant, int quantity)
{
	FoodID = foodID;
	FoodName = foodName;
	Category = category;
	Restaurant = restaurant;
	Quantity = quantity;
}

string Food::getName() 
{ 
	return FoodName;
}

string Food::getCategory() 
{
	return Category;
}

void Food::printFoodDetails() 
{
	cout << FoodName << endl;
}