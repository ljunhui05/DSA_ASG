//-----------------------------//
// Lim JunHui (S10242387K)     //
//-----------------------------//

#include <string>
#include <iostream>
using namespace std;
#include "Member.h";

//default constructor of Member class
Member::Member() 
{
	Username = "";
	Password = "";
	LoyaltyPoints = 0;
}

//Member constructor
Member::Member(int memberID, string name, string pass, double totalMoney, int loyaltyPoints)
{
	MemberID = memberID;
	Username = name;
	Password = pass;
	TotalMoney = totalMoney;
	LoyaltyPoints = loyaltyPoints;
}

//Returns the member objects ID
int Member::getID() 
{
	return MemberID;
}

//Returns the member objects Name
string Member::getName()
{
	return Username;
}

//Returns the length of the member objects Name
int Member::getNameLength() {
	return Username.size();
}

//Returns member objects Password
string Member::getPass() 
{
	return Password;
}

//Returns member objects TotalMoney
double Member::getMoney() 
{
	return TotalMoney;
}

//Returns member objects LoyaltyPoints
int Member::getPoints() 
{
	return LoyaltyPoints;
}

//Adds an amount to the TotalMoney of a member object and returns updated value
double Member::AddMoney(double amt) 
{
	TotalMoney += amt;
	return TotalMoney;
}

//Deducts an amount to the TotalMoney of a member object and returns updated value
double Member::DeductMoney(double cost) {
	TotalMoney -= cost;
	return TotalMoney;
}

//Adds LoyaltyPoints to the member object and returns amount of LoyaltyPoints earned
int Member::AddLoyaltyPoint(double orderCost)
{
	int loyaltyPointsEarned = orderCost / 3;
	LoyaltyPoints += loyaltyPointsEarned;
	return loyaltyPointsEarned;
}

//Deducts an amount of LoyaltyPoints of a member object and returns updated value
void Member::ClaimLoyaltyPoint(int claimedPoints)
{
	LoyaltyPoints -= claimedPoints;
}