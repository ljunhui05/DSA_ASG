#include <string>
#include <iostream>
using namespace std;
#include "Member.h";

Member::Member() 
{
	Username = "";
	Password = "";
	LoyaltyPoints = 0;
}

Member::Member(string name, string pass, double totalMoney, int loyaltyPoints)
{
	Username = name;
	Password = pass;
	TotalMoney = totalMoney;
	LoyaltyPoints = loyaltyPoints;
}

string Member::getName() const
{
	return Username;
}

int Member::AddMoney(double amt) 
{
	TotalMoney += amt;
	return TotalMoney;
}

void CreateOrder() 
{

}

void CancelOrder() 
{

}

int AddLoyaltyPoint() 
{
	return 0;
}

int ClaimLoyaltyPoint() 
{
	return 0;
}

void BrowseFood() 
{

}