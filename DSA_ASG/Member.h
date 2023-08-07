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
	int MemberID;
	string Username;
	string Password;
	int LoyaltyPoints;
	List<Food>* FoodList;
public:
	Member();
	Member(int MemberID, string Username, string Password);
	string getName();
	void CreateOrder();
	void CancelOrder();
	int AddLoyaltyPoint();
	int ClaimLoyaltyPoint();
	void BrowseFood();
};


