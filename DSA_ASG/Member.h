#pragma once
#include <string>
#include <iostream>
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
	string getName(); 
	int getNameLength();
	string getPass();
	double getMoney();
	double AddMoney(double amt);
	int AddLoyaltyPoint();
	int ClaimLoyaltyPoint();
	void BrowseFood();
};


