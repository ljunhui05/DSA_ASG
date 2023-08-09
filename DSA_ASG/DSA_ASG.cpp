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
    Food Food4(4, "Prawn Noodles", "Chinese", "Bishan", 7, 25);
    Food Food5(5, "Dim Sum", "Chinese", "Bishan", 8, 30);

    foodMenu.add(1, Food1);
    foodMenu.add(2, Food2);
    foodMenu.add(3, Food3);
    foodMenu.add(4, Food4);
    foodMenu.add(5, Food5);

    Food Food6(6, "Pizza", "Western", "Punggol", 12, 10);
    Food Food7(7, "Hot Dogs", "Western", "Punggol", 5, 50);
    Food Food8(8, "Carbonara", "Western", "Punggol", 7, 25);
    Food Food9(9, "Hamburger", "Western", "Punggol", 8, 30);
    Food Food10(10, "Creme Brulee", "Western", "Punggol", 11, 15);

    foodMenu.add(6, Food6);
    foodMenu.add(7, Food7);
    foodMenu.add(8, Food8);
    foodMenu.add(9, Food9);
    foodMenu.add(10, Food10);
}

void makeOrder() 
{
    int makeOrderOpt = -1;
    int quantityOpt = 0;
    bool confirm = true;
    List<Food> orderFoodList;
    cout << "+----------------------------+" << endl;
    cout << "+         Make Order         +" << endl;
    cout << "+----------------------------+" << endl;

    while (confirm == true) 
    {
        foodMenu.print();
        cout << "+----------------------------+" << endl;
        cout << "Enter 0 to confirm your order" << endl;
        cout << "" << endl;
        cout << "Please select an option:" << endl;
        cin >> makeOrderOpt;
        if (foodMenu.checkFoodExist(makeOrderOpt) == true)
        {
            cout << "What is the quantity you want?" << endl;
            cin >> quantityOpt;

            Food newFood(foodMenu.get(makeOrderOpt).getID(), foodMenu.get(makeOrderOpt).getName(),
                foodMenu.get(makeOrderOpt).getCategory(), foodMenu.get(makeOrderOpt).getRestaurant(),
                foodMenu.get(makeOrderOpt).getPrice(), quantityOpt);

            orderFoodList.add(newFood);


        }

        else if (makeOrderOpt == 0)
        {
            confirm = false;
        }

        else 
        {
            cout << "Enter a valid option!" << endl;
        }
    }
    

    Order newOrder(loggedInMember, orderFoodList, orderQueue.getLength());

    orderQueue.enqueue(newOrder);

    orderQueue.displayItems();

    cout << "Order Confirmed Successfully!" << endl;

}

void printOrder(Order& order) {
    cout << "+----------------------------+" << endl;
    cout << "OrderID: " << order.getOrderID() << endl;
    order.displayOrderDetails();
    cout << "+----------------------------+" << endl;
}

void cancelOrder() 
{
    List<Order> memberOrderList;
    cout << "+----------------------------+" << endl;
    cout << "+        Cancel Order        +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+        Your Orders         +" << endl;
    cout << "+----------------------------+" << endl;
    
    memberOrderList = orderQueue.getMemberOrder(loggedInMember);

    if (memberOrderList.getLength() == 0) {
        cout << "You do not currently have any orders" << endl;
    }

    else {
        memberOrderList.traverse(printOrder);
    }



}

void memberMainMenu() {

    cout << "+----------------------------+" << endl;
    cout << "         Hello " << loggedInMember.getName() << endl;
    cout << "+    How may we serve you?   +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+    [1] Make an Order       +" << endl;
    cout << "+    [2] Cancel an Order     +" << endl;
    cout << "+    [3] Manage Account      +" << endl;
    cout << "+    [4] Exit                +" << endl;
    cout << "+----------------------------+" << endl;

    int memberMainOpt = 0;

    while (memberMainOpt != 4)
    {
        cout << "Please select an option" << endl;
        cin >> memberMainOpt;

        if (memberMainOpt == 1)
        {
            makeOrder();
            memberMainMenu();
        }

        else if (memberMainOpt == 2)
        {
            cancelOrder();
            memberMainMenu();
        }

        else if (memberMainOpt == 3)
        {

        }

        else if (memberMainOpt == 4)
        {
            cout << "Goodbye! It was a pleasure serving you!" << endl;
            exit(0);
        }

        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

    


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
    cin >> memberMoney;

    Member newMember(memberUsername, memberPassword, memberMoney, 0);

    memberHashTable.add(newMember.getName(), newMember);

    loggedInMember = memberHashTable.get(memberUsername);

    memberMainMenu();
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

    if (memberHashTable.checkMemberExist(memberUsername) && memberHashTable.checkPass(memberUsername, memberPassword) == true)
    {
        loggedInMember = memberHashTable.get(memberUsername);
        cout << "Successful Login!" << endl;
        memberMainMenu();
    }

    else
    {
        int loginOpt = 3;
        cout << "Invalid Login Credentials!" << endl;
        cout << "Don't have an account?" << endl;
        cout << "Enter 1 to register an account. Enter 0 to return to the Login menu." << endl;
        cin >> loginOpt;

        if (loginOpt == 1)
        {
            registerMember();
        }

        else if(loginOpt == 0)
        {
            memberLogin();
        }

        else {
            cout << "Invalid input!" << endl;
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

    int mainOpt = 0;
    cin >> mainOpt;

    while (mainOpt != 4)
    {
        if (mainOpt == 1)
        {
            registerMember();
        }

        else if (mainOpt == 2)
        {
            printAdminLoginHeader();
        }

        else if (mainOpt == 3)
        {
            memberLogin();
        }

        else if (mainOpt == 4)
        {
            cout << "Goodbye! It was a pleasure serving you!" << endl;
            exit(0);
        }

        else
        {
            cout << "Please enter a valid input!" << endl;
            mainMenu();
        }
    }

}

int main(){
    initData();
    mainMenu();
}

