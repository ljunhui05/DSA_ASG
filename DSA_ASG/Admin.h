#pragma once
#include <string>
#include <iostream>
using namespace std;

class Admin 
{
private:
	string AdminID;
	string Password;

public:
	Admin();
	Admin(string AdminID, string Password);
	void ViewIncomingOrders();
	void UpdateOrderStatus();
	void ViewOrderCustoInfo();
};

