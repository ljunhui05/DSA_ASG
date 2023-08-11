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

//Lim JunHui (S10242387K)
//Input parameters: MemberID as memberID, member Username as name, member Password as pass, member TotalMoney
//as totalMoney and LoyaltyPoints as loyaltyPoints 
//Description: Member constructor
Member::Member(int memberID, string name, string pass, double totalMoney, int loyaltyPoints)
{
	MemberID = memberID;
	Username = name;
	Password = pass;
	TotalMoney = totalMoney;
	LoyaltyPoints = loyaltyPoints;
}

//Lim JunHui (S10242387K)
//Return value: MemberID as an integer 
//Description: Returns the member objects ID
int Member::getID() 
{
	return MemberID;
}

//Lim JunHui (S10242387K)
//Return value: Members Username as a string
//Description: Returns the member objects Name
string Member::getName()
{
	return Username;
}

//Lim JunHui (S10242387K)
//Return value: length of Member Username as integer
//Description: Returns the length of the member objects Name
int Member::getNameLength() {
	return Username.size();
}

//Lim JunHui (S10242387K)
//Return value: Member Password as string
//Description: Returns member objects Password
string Member::getPass() 
{
	return Password;
}

//Lim JunHui (S10242387K)
//Return value: Members TotalMoney as integer 
//Description: Returns member objects TotalMoney
double Member::getMoney() 
{
	return TotalMoney;
}

//Returns member objects LoyaltyPoints
int Member::getPoints() 
{
	return LoyaltyPoints;
}

//Lim JunHui (S10242387K)
//Input parameters: Amount to add to TotalMoney as double
//Return value: Member's new TotalMoney value as double
//Description: Adds an amount to the TotalMoney of a member object and returns updated value
double Member::AddMoney(double amt) 
{
	TotalMoney += amt;
	return TotalMoney;
}

//Lim JunHui (S10242387K)
//Input parameters: Amount to deduct from TotalMoney as double
//Return value: Member's new TotalMoney as double 
//Description: Deducts an amount to the TotalMoney of a member object and returns updated value
double Member::DeductMoney(double cost) {
	TotalMoney -= cost;
	return TotalMoney;
}

//Lim JunHui (S10242387K)
//Input parameters: Total cost of the order as double
//Return value: Number of loyalty points that have been earned as integer 
//Description: Adds LoyaltyPoints to the member object and returns amount of LoyaltyPoints earned
int Member::AddLoyaltyPoint(double orderCost)
{
	int loyaltyPointsEarned = orderCost / 3;
	LoyaltyPoints += loyaltyPointsEarned;
	return loyaltyPointsEarned;
}

//Lim JunHui (S10242387K)
//Input parameters: Amount to deduct from Member's LoyaltyPoints as integer 
//Description: Deducts an amount of LoyaltyPoints of a member object and returns updated value
void Member::ClaimLoyaltyPoint(int claimedPoints)
{
	LoyaltyPoints -= claimedPoints;
}