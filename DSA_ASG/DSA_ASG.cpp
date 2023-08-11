// DSA_ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <vector>
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
        string ID, name, password, money, points;
        if (getline(iss, ID, ',') && getline(iss, name, ',') && getline(iss, password, ',') && getline(iss, money, ',') && getline(iss, points)) {
            Member member (stoi(ID), name, password, stod(money), stoi(points));
            memberHashTable.add(name, member);
        }
    }

}

void updateCustomer(Member loggedInMember)
{
    ifstream inputFile("Members.csv");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return;
    }


    List<Member> members;

    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string ID, name, password, money, points;

        if (getline(iss, ID, ',') && getline(iss, name, ',') && getline(iss, password, ',') && getline(iss, money, ',') && getline(iss, points)) {
            Member member(stoi(ID), name, password, stod(money), stoi(points));
            members.add(member);
        }
    }

    inputFile.close();

    for (int i = 0; i < members.getLength(); i ++) {
        if (members.get(i).getID() == loggedInMember.getID()) {
            members.add(i, loggedInMember);
            members.remove(i+1);
            break;
        }
    }

    std::ofstream outputFile("Members.csv");
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    // Loop through the updated members list and write data to the output file
    for (int i = 0; i < members.getLength(); i++) {
        outputFile << members.get(i).getID() << "," << members.get(i).getName() << ","
            << members.get(i).getPass() << "," << members.get(i).getMoney() << ","
            << members.get(i).getPoints()<< endl;
    }

    outputFile.close();
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
    double orderCost = 0;
    bool makeOrderConfirm = true;
    List<Food> orderFoodList;
    std::cout << "+----------------------------+" << endl;
    std::cout << "+         Make Order         +" << endl;
    std::cout << "+----------------------------+" << endl;

    while (makeOrderConfirm == true) 
    {
        foodMenu.print();
        std::cout << "+----------------------------+" << endl;
        std::cout << "Enter 0 to confirm your order" << endl;
        std::cout << "" << endl;
        std::cout << "Please select an option:" << endl;
        cin >> makeOrderOpt;
        if (foodMenu.checkFoodExist(makeOrderOpt) == true)
        {
            std::cout << "What is the quantity you want?" << endl;
            cin >> quantityOpt;

            Food newFood(foodMenu.get(makeOrderOpt).getID(), foodMenu.get(makeOrderOpt).getName(),
                foodMenu.get(makeOrderOpt).getCategory(), foodMenu.get(makeOrderOpt).getRestaurant(),
                foodMenu.get(makeOrderOpt).getPrice(), quantityOpt);

            orderFoodList.add(newFood);


        }

        else if (makeOrderOpt == 0)
        {
            makeOrderConfirm = false;
        }

        else 
        {
            std::cout << "Enter a valid option!" << endl;
        }
    }
    
    for (int i = 0; i < orderFoodList.getLength(); i++)
    {
        double price = orderFoodList.get(i).getPrice();
        int quantity = orderFoodList.get(i).getQuantity();
        orderCost += price * quantity;
    }

    if (loggedInMember.getMoney() - orderCost >= 0) 
    {
        int pointsClaim;
        bool pointsClaimConfirm = true;
        if (loggedInMember.getPoints() > 0) {
            while (pointsClaimConfirm == true)
            {
                std::cout << "You currently have: " << loggedInMember.getPoints() << " Points" << endl;
                std::cout << "How many would you like to claim?" << endl;
                std::cin >> pointsClaim;
                
                if (pointsClaim > loggedInMember.getPoints() || pointsClaim < 0 || pointsClaim > orderCost) {
                    cout << "Please enter a valid input" << endl;
                }

                else {
                    pointsClaimConfirm = false;
                }
            }

            int earnedPoints = loggedInMember.AddLoyaltyPoint(orderCost);
            orderCost -= pointsClaim;
            loggedInMember.ClaimLoyaltyPoint(pointsClaim);
            std::cout << "+---------------------------------------------+" << endl;
            std::cout << "Your new Total is:$" << orderCost  << endl;
            std::cout << "You have earned: " << earnedPoints << " Points" << endl;
            std::cout << "You now have: " << loggedInMember.getPoints() << " Points" << endl;
            std::cout << "You have:$" << loggedInMember.DeductMoney(orderCost) << " left in your account" << endl; 
            std::cout << "+---------------------------------------------+" << endl;
            std::cout << "" << endl;
        }

        Order newOrder(loggedInMember, orderFoodList, orderQueue.getLength(), orderCost);

        orderQueue.enqueue(newOrder);

        newOrder.displayOrderDetails();

        std::cout << "Order Confirmed Successfully!" << endl;
        std::cout << "" << endl;
    }

    else {
        std::cout << "You do not have enough money in your account!" << endl;
    }



}

void printOrder(Order& order) {
    std::cout << "+----------------------------+" << endl;
    std::cout << "OrderID: " << order.getOrderID() << endl;
    order.displayOrderDetails();
    std::cout << "+----------------------------+" << endl;
}

void cancelOrder() 
{
    int cancelOrderOpt;
    List<Order> memberOrderList;
    List<Order> orderList;
    std::cout << "+----------------------------+" << endl;
    std::cout << "+        Cancel Order        +" << endl;
    std::cout << "+----------------------------+" << endl;
    std::cout << "" << endl;
    std::cout << "+----------------------------+" << endl;
    std::cout << "+        Your Orders         +" << endl;
    std::cout << "+----------------------------+" << endl;

    
    memberOrderList = orderQueue.getMemberOrder(loggedInMember);

    if (memberOrderList.getLength() == 0) {
        std::cout << "You do not currently have any orders" << endl;
    }

    else {
        
        for (int i = 0; i < memberOrderList.getLength(); i++) 
        {
            std::cout << "+----------------------------+" << endl;
            std::cout << "OrderID: " << memberOrderList.get(i).getOrderID() << endl;
            memberOrderList.get(i).displayOrderDetails();
            std::cout << "+----------------------------+" << endl;
        }
        std::cout << "Please select enter the OrderID of the order you would like to cancel: " << endl;
        cin >> cancelOrderOpt;
        for (int j = 0; j < orderQueue.getLength(); j++)  
        {
            Order orders;
            orderQueue.dequeue(orders);
            orderList.add(orders);
        }

        for (int k = 0; k < orderList.getLength(); k++)
        {
            if (orderList.get(k).getOrderID() == cancelOrderOpt)
            {
                orderList.remove(k);
            }
        }

        for (int l = 0; l < orderList.getLength(); l++) 
        {
            orderQueue.enqueue(orderList.get(l));
        }

        std::cout << "Order cancelled successfully!" << endl;
        
    }



}

void manageMemberAccount() {

    int manageMemberAccountOpt = -1; 
    cout << "+--------------------------------------+" << endl;
    cout << "+         Your Account Details         +" << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "+--------------------------------------+" << endl;
    cout << "   Money:$" << loggedInMember.getMoney() << endl;
    cout << "   Loyalty Points: " << loggedInMember.getPoints() << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "" << endl;
    cout << "Short on money? Enter 1 to top up!" << endl;
    cout << "Enter 0 to return to the main menu" << endl;
    cin >> manageMemberAccountOpt;
    if (manageMemberAccountOpt == 1) {
        double topUpAmt;
        cout << "Enter the amount you would like to top up: " << endl;
        cin >> topUpAmt; 
        loggedInMember.AddMoney(topUpAmt);
        cout << "Successfully topped up!" << endl;
        cout << "Your new balance is:$" << loggedInMember.getMoney() << endl;
    }

    else if (manageMemberAccountOpt == 0) 
    {

    }

    else {
        cout << "Please enter a valid input!" << endl; 
    }
}

void memberMainMenu() {
    string memberMainOpt = "";

    while (true)
    {

        std::cout << "+----------------------------+" << endl;
        std::cout << "         Hello " << loggedInMember.getName() << endl;
        std::cout << "+    How may we serve you?   +" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "+    [1] Make an Order       +" << endl;
        std::cout << "+    [2] Cancel an Order     +" << endl;
        std::cout << "+    [3] Manage Account      +" << endl;
        std::cout << "+    [4] Exit                +" << endl;
        std::cout << "+----------------------------+" << endl;



        std::cout << "Please select an option" << endl;
        cin >> memberMainOpt;

        if (memberMainOpt == "1")
        {
            makeOrder();
        }

        else if (memberMainOpt == "2")
        {
            cancelOrder();
        }

        else if (memberMainOpt == "3")
        {
            manageMemberAccount();
        }

        else if (memberMainOpt == "4")
        {
            std::cout << "Goodbye! It was a pleasure serving you!" << endl;
            updateCustomer(loggedInMember);
            exit(0);
        }

        else
        {
            std::cout << "Invalid Input!" << endl;
        }
    }


}

void printAdminLoginHeader() {
    std::cout << "+---------------------------------+" << endl;
    std::cout << "+         Login as Admin          +" << endl;
    std::cout << "+---------------------------------+" << endl;
}

void registerMember() {
    std::cout << "+---------------------------------+" << endl;
    std::cout << "+       Register as a Member      +" << endl;
    std::cout << "+---------------------------------+" << endl;
    std::cout << "" << endl;
    string memberUsername;
    string memberPassword;
    double memberMoney = 0;
    std::cout << "Please enter a username: " << endl;
    cin >> memberUsername;

    std::cout << "Please enter a password: " << endl;
    cin >> memberPassword;

    std::cout << "Please enter how much money you would like to add to your account:" << endl;
    cin >> memberMoney;

    Member newMember(memberHashTable.getLength(), memberUsername, memberPassword, memberMoney, 0);

    memberHashTable.add(newMember.getName(), newMember);

    loggedInMember = memberHashTable.get(memberUsername);

    ofstream file("Members.csv", std::ios::app); // Open file in append mode

    if (!file.is_open()) {
        std::cerr << "Error opening file: Customer.csv" << std::endl;
    }

    file << memberHashTable.getLength() << "," << memberUsername << "," << memberPassword << ","
        << memberMoney << "," << "0" << endl;

    file.close();

    memberMainMenu();
}

void memberLogin() {
    std::cout << "+---------------------------------+" << endl;
    std::cout << "+        Login as Member          +" << endl;
    std::cout << "+---------------------------------+" << endl;
    std::cout << "" << endl;
    string memberUsername = "";
    string memberPassword = "";
    double memberMoney = 0;
    std::cout << "Please enter your username: " << endl;
    cin >> memberUsername;

    std::cout << "Please enter your password: " << endl;
    cin >> memberPassword;

    if (memberHashTable.checkMemberExist(memberUsername) && memberHashTable.checkPass(memberUsername, memberPassword) == true)
    {
        loggedInMember = memberHashTable.get(memberUsername);
        std::cout << "Successful Login!" << endl;
        memberMainMenu();
    }

    else
    {
        int loginOpt = 3;
        std::cout << "Invalid Login Credentials!" << endl;
        std::cout << "Don't have an account?" << endl;
        std::cout << "Enter 1 to register an account. Enter 0 to return to the Login menu." << endl;
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
            std::cout << "Invalid input!" << endl;
        }
    }

}

void mainMenu() {
    string mainOpt = "";
    while (true)
    {
        std::cout << "+----------------------------+" << endl;
        std::cout << "+     Welcome to The Bear!   +" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "+   Please select an option  +" << endl;
        std::cout << "+   [1] Register as a Member +" << endl;
        std::cout << "+   [2] Login as Admin       +" << endl;
        std::cout << "+   [3] Login as Member      +" << endl;
        std::cout << "+   [4] Exit                 +" << endl;
        std::cout << "+----------------------------+" << endl;


        cin >> mainOpt;

        if (mainOpt == "1")
        {
            registerMember();
        }

        else if (mainOpt == "2")
        {
            printAdminLoginHeader();
        }

        else if (mainOpt == "3")
        {
            memberLogin();
        }

        else if (mainOpt == "4")
        {
            std::cout << "Goodbye! It was a pleasure serving you!" << endl;
            updateCustomer(loggedInMember);
            exit(0);
        }

        else
        {
            std::cout << "Please enter a valid input!" << endl;
        }
    }

}

int main(){
    initData();
    mainMenu();
}

