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

int Food::getID() 
{
	return FoodID;
}

string Food::getName() 
{ 
	return FoodName;
}

string Food::getCategory() 
{
	return Category;
}

string Food::getRestaurant() 
{
	return Restaurant;
}

int Food::getPrice() 
{
	return Price;
}

int Food::getQuantity() 
{
	return Quantity;
}

void Food::printFoodDetails() 
{
	cout << "Food:" << FoodName << endl;
	cout << "Quantity:" << Quantity << endl;
}