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
	int OrderID;
	Member MemberDetails;
	double OrderTotal;
public:
	Order();
	~Order();
	string OrderStatus;
	List<Food> FoodList;
	Order(Member MemberDetails, List<Food> FoodList, int OrderQueueLen, double OrderTotal, string OrderStatus);
	void displayOrderDetails();
	Member getMemberDetails();
	void setStatus(string OrderStatus);
	string getStatus() ;
	int getOrderID();
	string getOrderStatusString(string status);
	const Member& getCustomerDetails() ;
};