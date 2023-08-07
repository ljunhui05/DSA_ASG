#pragma once
#include<string>
#include<iostream>
#include "Food.h"
#include "Member.h"
#include"List.h"
using namespace std;

class Order
{
private:
	Member MemberDetails;
	List<Food>* FoodList;
	string OrderStatus;
public:
	Order();
	~Order();
	Order(Member MemberDetails, List<Food>* FoodList);
	void displayFood();
	void displayOrderDetails();
};
