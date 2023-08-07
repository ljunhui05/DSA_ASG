#include <string>
#include <iostream>
using namespace std;
#include "Food.h"

Food::Food() 
{

}

Food::Food(int foodID, string foodName, string category, string restaurant, int price,int quantity)
{
	FoodID = foodID;
	FoodName = foodName;
	Category = category;
	Restaurant = restaurant;
	Price = price;
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