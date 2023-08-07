#pragma once
#include<string>
#include<iostream>
#include "Order.h"
using namespace std;

Order::Order() 
{

}

Order::~Order() 
{
	if (FoodList != nullptr) {
		delete FoodList;
		FoodList = nullptr;
	}
}

Order::Order(Member memberDetails, List<Food>* foodList) 
{
	MemberDetails = memberDetails;
	FoodList = foodList;
	OrderStatus = "unprepared";
}

void Order::displayFood() 
{
	for (int i = 0; i < FoodList->getLength(); i++) 
	{
		Food Food = FoodList->get(i);
		Food.printFoodDetails();
	}
}

void Order::displayOrderDetails()
{
	cout << MemberDetails.getName()<< endl;
	cout << FoodList->getLength() << endl;
	cout << OrderStatus << endl;
}