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
Order::Order(Member memberDetails, List<Food> foodList , int orderQueueLen, double orderTotal, string orderStatus)
{
	OrderID = memberDetails.getNameLength() + orderQueueLen;
	MemberDetails = memberDetails;
	FoodList = foodList;
	OrderStatus = orderStatus;
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
	/*std::cout << "+----------------------------+ " << endl;
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
	cout << statusStr << endl;*/
}

string Order::getStatus() 
{
	return OrderStatus; // Return the current order status
}

void Order::setStatus(string newStatus)
{
	OrderStatus = getOrderStatusString(newStatus); // Set the new order status
}

//Lim JunHui (S10242387K)
//Return value: OrderID as a int
//Description: This function returns the OrderID of the Order object
int Order::getOrderID()
{
	return OrderID; // Return the order ID
}

const Member& getCustomerDetails() 
{
	return Member::Member(); // Return the Member object representing customer details
}

string getOrderStatusString(string status)
{
	if (status == "Pending") {
		return "Pending";
	}
	else if (status == "Prepared") {
		return "Prepared";
	}
	else if (status == "Delivered") {
		return "Delivered";
	}
	else if (status == "Cancelled") {
		return "Cancelled";
	}
	else {
		return "Unknown"; // Handle any other status strings
	}
}