//-----------------------------//
// Lim JunHui (S10242387K)     //
//-----------------------------//

#pragma once
#include <string>
#include <iostream>
#include "Food.h"
#include "List.h"

class Member 
{
private:
	int MemberID;
	string Username;
	string Password;
	double TotalMoney;
	int LoyaltyPoints;
public:
	Member();
	Member(int MemberID, string Username, string Password, double TotalMoney, int LoyaltyPoints);
	int getID();
	string getName(); 
	int getNameLength();
	string getPass();
	double getMoney();
	int getPoints();
	double AddMoney(double Amt);
	double DeductMoney(double Cost);
	int AddLoyaltyPoint(double OrderCost);
	void ClaimLoyaltyPoint(int ClaimedPoints);
};


