#pragma once
#include<string>
#include<iostream>
#include "Order.h"
using namespace std;



Order::~Order() 
{
	if (FoodList != nullptr) {
		delete FoodList;
		FoodList = nullptr;
	}
}

Order::Order(Member memberDetails, List<Food>* foodList, OrderStatus newStatus)
{
	MemberDetails = memberDetails;
	FoodList = foodList;
	setStatus(newStatus);
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
	string statusStr;
	switch (status) {
	case OrderStatus::Pending:
		statusStr = "Pending";
		break;
	case OrderStatus::Prepared:
		statusStr = "Prepared";
		break;
	case OrderStatus::Delivered:
		statusStr = "Delivered";
		break;
	case OrderStatus::Cancelled:
		statusStr = "Cancelled";
		break;
	}
	cout << statusStr << endl;
}

Order::OrderStatus Order::getStatus() const
{
	return status; // Return the current order status
}

void Order::setStatus(OrderStatus newStatus)
{
	status = newStatus; // Set the new order status
}

int Order::getOrderId() const
{
	return orderId; // Return the order ID
}

const Member& Order::getCustomerDetails() const
{
	return MemberDetails; // Return the Member object representing customer details
}

string Order::getOrderStatusString(OrderStatus status)
{
	switch (status) {
	case OrderStatus::Pending:
		return "Pending";
	case OrderStatus::Prepared:
		return "Prepared";
	case OrderStatus::Delivered:
		return "Delivered";
	case OrderStatus::Cancelled:
		return "Cancelled";
	default:
		return "Unknown";
	}
}