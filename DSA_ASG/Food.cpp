#include <string>
#include <iostream>
using namespace std;
#include "Food.h"

//Lim JunHui (S10242387K) 
//Description: Default constructor of Food 
Food::Food() 
{

}

//Lim JunHui (S10242387K)
//Input parameters: The ID of the food as foodID, name of the food as foodName, category of the food as category,
//restaurant the food is from as restaurant, price of the food as price and quantity of food as quantity 
//Description: Constructor of Food
Food::Food(int foodID, string foodName, string category, string restaurant, int price,int quantity)
{
	FoodID = foodID;
	FoodName = foodName;
	Category = category;
	Restaurant = restaurant;
	Price = price;
	Quantity = quantity;
}

//Lim JunHui (S10242387K)
//Return value: FoodID as int
//Description: This function returns the ID of the food as a integer
int Food::getID() 
{
	return FoodID;
}

//Lim JunHui (S10242387K)
//Return value: FoodName as string
//Description: This function returns the Name of the food as a string
string Food::getName() 
{ 
	return FoodName;
}

//Lim JunHui (S10242387K)
//Return value: Food category as string
//Description: This function returns the category of the food as a string
string Food::getCategory() 
{
	return Category;
}

//Lim JunHui (S10242387K)
//Return value: Restaurant of Food as string
//Description: This function returns the name of the restaurant of the food as a string
string Food::getRestaurant() 
{
	return Restaurant;
}

//Lim JunHui (S10242387K)
//Return value: price of Food as int
//Description: This function returns the prce of the Food as a integer
int Food::getPrice() 
{
	return Price;
}

//Lim JunHui (S10242387K)
//Return value: Food quantity as int
//Description: This function returns the quantity of the food as a integer
int Food::getQuantity() 
{
	return Quantity;
}

//Lim JunHui (S10242387K)
//Description: This function prints the Food object details
void Food::printFoodDetails() 
{
	cout << "Food:" << FoodName;
	cout << " Quantity:" << Quantity << endl;
}

