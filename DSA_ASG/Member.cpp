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

Member::Member(int memberID, string name, string pass, double totalMoney, int loyaltyPoints)
{
	MemberID = memberID;
	Username = name;
	Password = pass;
	TotalMoney = totalMoney;
	LoyaltyPoints = loyaltyPoints;
}

int Member::getID() 
{
	return MemberID;
}

string Member::getName()
{
	return Username;
}

int Member::getNameLength() {
	return Username.size();
}



string Member::getPass() 
{
	return Password;
}

double Member::getMoney() 
{
	return TotalMoney;
}

int Member::getPoints() 
{
	return LoyaltyPoints;
}

double Member::AddMoney(double amt) 
{
	TotalMoney += amt;
	return TotalMoney;
}

double Member::DeductMoney(double cost) {
	TotalMoney -= cost;
	return TotalMoney;
}

int Member::AddLoyaltyPoint(double orderCost)
{
	int loyaltyPointsEarned = orderCost / 3;
	LoyaltyPoints += loyaltyPointsEarned;
	return loyaltyPointsEarned;
}

void Member::ClaimLoyaltyPoint(int claimedPoints)
{
	LoyaltyPoints -= claimedPoints;
}