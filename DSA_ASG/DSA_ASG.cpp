// DSA_ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <iomanip>
using namespace std;

#include "Admin.h";
#include"Dictionary.h";
#include"Food.h";
#include"HashTable.h";
#include"List.h";
#include"Member.h"
#include"Order.h";
#include"OrderQueue.h";


Dictionary foodMenu;
List<Admin>adminList;
HashTable memberHashTable;
Member loggedInMember;
Queue orderQueue;

void initCustomer() {

    ifstream inFile("Members.csv");
    if (!inFile) {
        cerr << "Error opening Members.csv for reading." << std::endl;
        return;
    }

    string line;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string name, password, money, points;
        if (getline(iss, name, ',') && getline(iss, password, ',') && getline(iss, money, ',') && getline(iss, points)) {
            Member member (name, password, stod(money), stoi(points));
            memberHashTable.add(name, member);
        }
    }

}

void initData() 
{
    initCustomer();

    Admin Admin1("Admin1", "passAdmin1");

    adminList.add(Admin1);

    Food Food1(1, "Pizza", "Western", "Bishan", 12, 10);
    Food Food2(2, "Hot Dogs", "Western", "Bishan", 5, 50);
    Food Food3(3, "Carbonara", "Western", "Bishan", 7, 25);
    Food Food4(6, "Prawn Noodles", "Chinese", "Bishan", 7, 25);
    Food Food5(7, "Dim Sum", "Chinese", "Bishan", 8, 30);

    foodMenu.add("PizzaBishan", Food1);
    foodMenu.add("HotDogsBishan", Food2);
    foodMenu.add("CarbonaraBishan", Food3);
    foodMenu.add("PrawnNoodles", Food4);
    foodMenu.add("DimSum", Food5);

    Food Food6(1, "Pizza", "Western", "Punggol", 12, 10);
    Food Food7(2, "Hot Dogs", "Western", "Punggol", 5, 50);
    Food Food8(3, "Carbonara", "Western", "Punggol", 7, 25);
    Food Food9(4, "Hamburger", "Western", "Punggol", 8, 30);
    Food Food10(5, "Creme Brulee", "Western", "Punggol", 11, 15);

    foodMenu.add("PizzaPunggol", Food6);
    foodMenu.add("HotDogsPunggol", Food7);
    foodMenu.add("CarbonaraPunggol", Food8);
    foodMenu.add("Hamburger", Food9);
    foodMenu.add("CremeBrulee", Food10);
}

void printFoodMenu()
{
    foodMenu.print();
}

void memberMainMenu() {

    cout << "+----------------------------+" << endl;
    cout << "+    How may we serve you?   +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+    [1] Make an Order       +" << endl;
    cout << "+    [2] Cancel an Order     +" << endl;
    cout << "+    [3] Manage Account      +" << endl;
    cout << "+    [4] Exit                +" << endl;
    cout << "+----------------------------+" << endl;

    int opt = 0;
    while (opt != 4)
    {
        cout << "Please select an option" << endl;
        cin >> opt;

        if (opt == 1)
        {
            printFoodMenu();
        }

        else if (opt == 2)
        {

        }

        else if (opt == 3)
        {

        }

        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

    cout << "Goodbye! It was a pleasure serving you!" << endl;


}

void printAdminLoginHeader() {
    cout << "+---------------------------------+" << endl;
    cout << "+         Login as Admin          +" << endl;
    cout << "+---------------------------------+" << endl;
}



void registerMember() {
    cout << "+---------------------------------+" << endl;
    cout << "+       Register as a Member      +" << endl;
    cout << "+---------------------------------+" << endl;
    cout << "" << endl;
    string memberUsername = "";
    string memberPassword = "";
    double memberMoney = 0;
    cout << "Please enter a username: " << endl;
    cin >> memberUsername;

    cout << "Please enter a password: " << endl;
    cin >> memberPassword;

    cout << "Please enter how much money you would like to add to your account:" << endl;

    try
    {
        cin >> memberMoney;
    }
    catch (const std::exception&)
    {
        cout << "Invalid Amount!" << endl;
    }



    Member newMember(memberUsername, memberPassword, memberMoney, 0);

    memberHashTable.add(newMember.getName(), newMember);
}

void memberLogin() {
    cout << "+---------------------------------+" << endl;
    cout << "+        Login as Member          +" << endl;
    cout << "+---------------------------------+" << endl;
    cout << "" << endl;
    string memberUsername = "";
    string memberPassword = "";
    double memberMoney = 0;
    cout << "Please enter your username: " << endl;
    cin >> memberUsername;

    cout << "Please enter your password: " << endl;
    cin >> memberPassword;

    if (memberHashTable.checkExist(memberUsername) == true)
    {
        loggedInMember = memberHashTable.get(memberUsername);
        cout << "Successful Login!" << endl;
        memberMainMenu();
    }

    else
    {
        string loginOpt = "";
        cout << "Invalid Login Credentials!" << endl;
        cout << "Don't have an account?" << endl;
        cout << "Enter 1 to register an account. Enter anything to return to the Login menu." << endl;
        cin >> loginOpt;

        if (loginOpt == "1")
        {
            registerMember();
        }

        else
        {
            memberLogin();
        }
    }

}

void mainMenu() {
    cout << "+----------------------------+" << endl;
    cout << "+     Welcome to The Bear!   +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+   Please select an option  +" << endl;
    cout << "+   [1] Register as a Member +" << endl;
    cout << "+   [2] Login as Admin       +" << endl;
    cout << "+   [3] Login as Member      +" << endl;
    cout << "+   [4] Exit                 +" << endl;
    cout << "+----------------------------+" << endl;

    int opt = 0;
    cin >> opt;

    while (opt != 4) 
    {
        if (opt == 1)
        {
            registerMember();
        }

        else if (opt == 2)
        {
            printAdminLoginHeader();
        }

        else if (opt == 3)
        {
            memberLogin();
        }

        else
        {
            cout << "Please enter a valid input!" << endl;
            mainMenu();
        }
    }

    cout << "Goodbye! It was a pleasure serving you!" << endl;

}

int main(){
    initData();
    //mainMenu();
    registerMember();
}

