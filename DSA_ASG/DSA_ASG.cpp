// DSA_ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <vector>
using namespace std;

#include"Admin.h";
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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function reads the csv file that contains all the Members   //
// information, and adds them to a HashTable to for accessing later.//
//------------------------------------------------------------------//
void initMember() {

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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// Input parameters: Member object as loggedInMember                //
// This function updates the current logged in member's attributes  //
// after their session ends. It takes the input parameter of the    //
// currently logged in member.                                      //
//------------------------------------------------------------------//
void updateMember(Member loggedInMember)
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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function initialises all the data needed to run this program//
// like the Members, Admin, Food Dictionary                         //
//------------------------------------------------------------------//
void initData() 
{
    initMember();

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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function enables the Member to make an order. The function  //
// displays all the food that the Member can order from the         //
// dictionary of Food objects. After the Member makes a selection of//
// Food, the system adds loyalty points based on the order total    //
// before the claim of loyalty points. Then the system subtracts the//
// amount of loyalty points claimed, from the Member and subtracts  //
// the corresponding amount of points from the order total          //
//------------------------------------------------------------------//
void makeOrder() 
{
    string makeOrderOpt = "";
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
        if (foodMenu.checkFoodExist(stoi(makeOrderOpt)) == true)
        {
            std::cout << "What is the quantity you want?" << endl;
            while (!(cin >> quantityOpt)) {
                cout << "Invalid Input! Try again:" << endl;
                cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            Food newFood(foodMenu.get(stoi(makeOrderOpt)).getID(), foodMenu.get(stoi(makeOrderOpt)).getName(),
                foodMenu.get(stoi(makeOrderOpt)).getCategory(), foodMenu.get(stoi(makeOrderOpt)).getRestaurant(),
                foodMenu.get(stoi(makeOrderOpt)).getPrice(), quantityOpt);

            orderFoodList.add(newFood);


        }

        else if (makeOrderOpt == "0")
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
                while (!(std::cin >> pointsClaim)) {
                    cout << "Invalid Input! Try again:" << endl;
                    cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function makes use of the displayOrderDetails function in   //
// the Order class. It formats the information of the order in a    //
// readable form for the member                                     //
//------------------------------------------------------------------//

void printOrder(Order& order) {
    std::cout << "+----------------------------+" << endl;
    std::cout << "OrderID: " << order.getOrderID() << endl;
    order.displayOrderDetails();
    std::cout << "+----------------------------+" << endl;
}

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function loads in all the orders that the member has using  //
// the getMemberOrder function in orderQueue. Then based on the     //
// member's input, it cancels the order based on the OrderID        //
//------------------------------------------------------------------//

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
        while (!(std::cin >> cancelOrderOpt)) {
            std::cout << "Invalid Input! Try again:" << endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function allows for the member to be able to see their      //
// account details. This function also allows for the member to be  //
// able to add money to their account using the AddMoney function in//
// the Member class                                                 //
//------------------------------------------------------------------//

void manageMemberAccount() {

    string manageMemberAccountOpt = "";
    cout << "+--------------------------------------+" << endl;
    cout << "+         Your Account Details         +" << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "+--------------------------------------+" << endl;
    cout << "   Money:$" << loggedInMember.getMoney() << endl;
    cout << "   Loyalty Points: " << loggedInMember.getPoints() << endl;
    cout << "+--------------------------------------+" << endl;

    cout << "" << endl;

    while (true) {
        std::cout << "Short on money? Enter 1 to top up!" << endl;
        std::cout << "Enter 0 to return to the main menu" << endl;
        std::cin >> manageMemberAccountOpt;

        if (manageMemberAccountOpt == "1") {
            double topUpAmt;
            cout << "Enter the amount you would like to top up: " << endl;
            while (!(std::cin >> topUpAmt)) {
                std::cout << "Invalid Input! Try again:" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            loggedInMember.AddMoney(topUpAmt);
            std::cout << "Successfully topped up!" << endl;
            std::cout << "Your new balance is:$" << loggedInMember.getMoney() << endl;
            return;
        }

        else if (manageMemberAccountOpt == "0")
        {
            return;
        }

        else {
            cout << "Please enter a valid input!" << endl;
        }
    }

}

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function prints a header with a message with the member's   // 
// name and also prints the menu with all the actions that the      //
// member can do. Based on the member's selection of action, this   //
// function calls the respective functions                          // 
//------------------------------------------------------------------//

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
            updateMember(loggedInMember);
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
    std::cout << "" << endl;
    /*
    string AdminUsername = "";
    string AdminPassword = "";
    std::cout << "Please enter your username: " << endl;
    cin >> adminUsername;

    std::cout << "Please enter your password: " << endl;
    cin >> adminPassword;

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

        else if (loginOpt == 0)
        {
            memberLogin();
        }

        else {
            std::cout << "Invalid input!" << endl;
        }
    }*/

}

void adminMainMenu() {
    string adminMainOpt = "";

    while (true)
    {

        std::cout << "+----------------------------+" << endl;
        std::cout << "         Hello                "  << endl;
        std::cout << "+ What would you like to do? +" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "" << endl;
        std::cout << "+----------------------------+" << endl;
        std::cout << "+ [1] View incoming orders+"    << endl;
        std::cout << "+ [2] Update status of orders+" << endl;
        std::cout << "+ [0] Exit                   +" << endl;
        std::cout << "+----------------------------+" << endl;



        std::cout << "Please select an option" << endl;
        cin >> adminMainOpt;

        if (adminMainOpt == "1")
        {
            ViewIncomingOrders();
        }

        else if (adminMainOpt == "2")
        {
            UpdateOrderStatus();
        }

        else if (adminMainOpt == "0")
        {
            std::cout << "Goodbye!!" << endl;
            exit(0);
        }

        else
        {
            std::cout << "Invalid Input!" << endl;
        }
    }


}

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function allows for a new user to register as a Member.     //
// After the user inputs their username, password and amount of     //
// money, it creates a new Member object then adds it to the        //
// HashTable of members. This function also appends this new member //
// to the csv file                                                  //
//------------------------------------------------------------------//

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
    while (!(std::cin >> memberMoney)) {
        std::cout << "Invalid Input! Try again:" << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


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

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function allows the user to login into a member account. By //
// using the checkMemberExist and checkPass functions in the        //
// HashTable class, it prints a success message and redirects the   //
// user to the memberMainMenu if it is a valid Member account.      //
// Otherwise it prompts the user if they want to register or return //
// to the login menu                                                //   
//------------------------------------------------------------------//
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
        string loginOpt = "";
        std::cout << "Invalid Login Credentials!" << endl;
        while (true) {
            
            std::cout << "Don't have an account?" << endl;
            std::cout << "Enter 1 to register an account. Enter 0 to return to the Login menu." << endl;
            cin >> loginOpt;

            if (loginOpt == "1")
            {
                registerMember();
            }

            else if (loginOpt == "0")
            {
                memberLogin();
            }

            else {
                std::cout << "Invalid input!" << endl;
            }
        }

    }

}

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function prints a welcome message in a header, and prompts  //
// the user to enter option of the action that they would like to   //
// do. Based on the user's input, it calls the respective functions // 
//------------------------------------------------------------------//
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
            updateMember(loggedInMember);
            exit(0);
        }

        else if (mainOpt == "5")
        {

        }

        else
        {
            std::cout << "Please enter a valid input!" << endl;
        }
    }

}

//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This function calls the initData function to load the data needed//
// and the mainMenu function.                                       //
//------------------------------------------------------------------//
int main(){
    initData();
    mainMenu();
}

