#pragma once
#include <string>
#include <iostream>
#pragma once
#include <iostream>
#include <string>

#include "Food.h"
#include "List.h"

class Member 
{
private:
	string Username;
	string Password;
	double TotalMoney;
	int LoyaltyPoints;
public:
	Member();
	Member(string Username, string Password, double TotalMoney, int loyaltyPoints);
	string getName() const;
	int AddMoney(double amt);
	void CreateOrder();
	void CancelOrder();
	int AddLoyaltyPoint();
	int ClaimLoyaltyPoint();
	void BrowseFood();
};


