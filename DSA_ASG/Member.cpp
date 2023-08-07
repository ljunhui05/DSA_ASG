#include <string>
#include <iostream>
using namespace std;
#include "Member.h";

Member::Member() 
{
	MemberID = 0;
	Username = "";
	Password = "";
	LoyaltyPoints = 0;
	FoodList = new List<Food>();
}

Member::Member(int memberID, string name, string pass)
{
	MemberID = memberID;
	Username = name;
	Password = pass;
}

string Member::getName() 
{
	return Username;
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