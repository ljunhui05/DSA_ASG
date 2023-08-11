//-----------------------------//
// Lim JunHui (S10242387K)     //
//-----------------------------//
#pragma once
#include<string>
#include<iostream>
#include "Order.h"
using namespace std;

//Lim JunHui (S10242387K)
//Description: Default constructor of Order class
Order::Order() 
{

}

//Lim JunHui (S10242387K)
//Description: Destructor for Order class
Order::~Order() 
{

}

//Lim JunHui (S10242387K)
//Input parameters: Member object as memberDetails, List of food objects as foodList, length of the order queue as
//orderQueueLen and total cost of the order as orderTotal
//Description: Constructor for Order class
Order::Order(Member memberDetails, List<Food> foodList , int orderQueueLen, double orderTotal)
{
	OrderID = memberDetails.getNameLength() + orderQueueLen;
	MemberDetails = memberDetails;
	FoodList = foodList;
	OrderStatus = "Unprepared";
	OrderTotal = orderTotal;
//	setStatus(newStatus);
}

//Lim JunHui (S10242387K)
//Return value: Member object
//Description: This function returns the member details of the Order object as a Member object
Member Order::getMemberDetails() {
	return MemberDetails;
}

//Lim JunHui (S10242387K)
//Description: This function displays the details of the Order object.
void Order::displayOrderDetails()
{
	std::cout << "+---------Your Order---------+ " << endl;
	for (int i = 0; i < FoodList.getLength(); i++)
	{

		Food Food = FoodList.get(i);
		Food.printFoodDetails();
	}
	std::cout << "+----------------------------+ " << endl;
/*	string statusStr;
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
	cout << statusStr << endl;*/
}

/*Order::OrderStatus Order::getStatus() const
{
	return status; // Return the current order status
}

void Order::setStatus(OrderStatus newStatus)
{
	status = newStatus; // Set the new order status
}*/

//Lim JunHui (S10242387K)
//Return value: OrderID as a int
//Description: This function returns the OrderID of the Order object
int Order::getOrderID()
{
	return OrderID; // Return the order ID
}

/*const Member& Order::getCustomerDetails() const
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
	cout << "Items Ordered: " << FoodList.getLength();
	cout << " Order Status: " << OrderStatus << endl;
}*/