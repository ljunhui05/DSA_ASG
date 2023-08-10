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

double Member::AddMoney(double amt) 
{
	TotalMoney += amt;
	return TotalMoney;
}

int Member::AddLoyaltyPoint()
{
	return 0;
}

int Member::ClaimLoyaltyPoint()
{
	return 0;
}

void Member::BrowseFood()
{

}