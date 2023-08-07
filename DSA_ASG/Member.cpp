#include <string>
#include <iostream>
using namespace std;
#include "Member.h";

Member::Member() 
{
	Username = "";
	Password = "";
	LoyaltyPoints = 0;
	FoodList = new List<Food>();
}

Member::Member(string name, string pass, int totalMoney)
{
	Username = name;
	Password = pass;
	TotalMoney = totalMoney;
	LoyaltyPoints = 0;
	FoodList = new List<Food>();
}

string Member::getName() 
{
	return Username;
}

int Member::AddMoney(int amt) 
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