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
	FoodList = new List();
}

Member::Member(int memberID, string name, string pass)
{
	MemberID = memberID;
	Username = name;
	Password = pass;
}

void CreateOrder() 
{

}

void CancelOrder() 
{

}

int AddLoyaltyPoint() 
{

}

int ClaimLoyaltyPoint() 
{

}

void BrowseFood() 
{

}