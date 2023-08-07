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
	int TotalMoney;
	int LoyaltyPoints;
	List<Food>* FoodList;
public:
	Member();
	Member(string Username, string Password, int TotalMoney);
	string getName();
	int AddMoney(int amt);
	void CreateOrder();
	void CancelOrder();
	int AddLoyaltyPoint();
	int ClaimLoyaltyPoint();
	void BrowseFood();
};


