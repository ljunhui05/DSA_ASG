#pragma once
#include<string>
#include<iostream>
#include "Food.h"
#include "Member.h"
#include"List.h"
using namespace std;

class Order
{
public:
	enum class OrderStatus {
		Pending,
		Prepared,
		Delivered,
		Cancelled
	};
	Order();
	~Order();
	Order(Member MemberDetails, List<Food>* FoodList, OrderStatus newStatus);
	void displayFood();
	void displayOrderDetails();
	void setStatus(OrderStatus newStatus);
	OrderStatus getStatus() const;
	int getOrderId() const;
	const Member& getCustomerDetails() const;
	static string getOrderStatusString(OrderStatus status);

private:
	Member MemberDetails;
	List<Food>* FoodList;
	OrderStatus status;
	int orderId;
};
