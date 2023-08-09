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
	List<Food> FoodList;
	string OrderStatus;
	int orderID;
public:
	/*enum class OrderStatus {
		Pending,
		Prepared,
		Delivered,
		Cancelled
	};*/
	Order();
	~Order();
	Order(Member MemberDetails, List<Food> FoodList, int OrderQueueLen);
	void displayFood();
	void displayOrderDetails();
	Member getMemberDetails();
	//void setStatus(OrderStatus newStatus);
	//OrderStatus getStatus() const;
	int getOrderID();
	//const Member& getCustomerDetails() const;
	//static string getOrderStatusString(OrderStatus status);
};