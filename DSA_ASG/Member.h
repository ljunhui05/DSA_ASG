#pragma once
#include <string>
#include <iostream>
using namespace std;

#include "Food.h"
#include "List.h"

class Member 
{
private:
	int MemberID;
	string Username;
	string Password;
	int LoyaltyPoints;
	List* FoodList;
public:
	Member();
	Member(int MemberID, string Username, string Password);
	void CreateOrder();
	void CancelOrder();
	int AddLoyaltyPoint();
	int ClaimLoyaltyPoint();
	void BrowseFood();
};


