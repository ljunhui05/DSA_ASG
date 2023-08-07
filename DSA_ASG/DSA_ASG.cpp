// DSA_ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
using namespace std;

#include "Admin.h";
#include"Dictionary.h";
#include"Food.h";
#include"HashTable.h";
#include"List.h";
#include"Member.h"
#include"Order.h";
#include"OrderQueue.h";


void initData() 
{
    Dictionary foodMenu;
    List<Admin>adminList;
    HashTable memberHashTable;

    Member Member1("JunHui", "passJunHui", 100);
    Member Member2("Ervin", "passErvin", 50);
    Member Member3("Keene", "passKeene", 1000 );

    memberHashTable.add(Member1.getName(), Member1);
    memberHashTable.add(Member2.getName(), Member2);
    memberHashTable.add(Member3.getName(), Member3); 

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

void printMainMenu() {
    cout << "+----------------------------+" << endl;
    cout << "+     Welcome to The Bear!   +" << endl;
    cout << "+----------------------------+" << endl;
    cout << "" << endl;
    cout << "+----------------------------+" << endl;
    cout << "+   Please select an option  +" << endl;
    cout << "+   1) Register as a Member  +" << endl;
    cout << "+   2) Login as Admin        +" << endl;
    cout << "+   3) Login as Member       +" << endl;
    cout << "+----------------------------+" << endl;
}


void printRegisterMemberHeader(){
    cout << "+---------------------------------+" << endl;
    cout << "+       Register as a Member      +" << endl;
    cout << "+---------------------------------+" << endl;
}
void printAdminLoginHeader() {
    cout << "+---------------------------------+" << endl;
    cout << "+         Login as Admin          +" << endl;
    cout << "+---------------------------------+" << endl;
}

void printMemberLoginHeader() {
    cout << "+---------------------------------+" << endl;
    cout << "+        Login as Member          +" << endl;
    cout << "+---------------------------------+" << endl;
}

void registerMember() {
    string memberEmail = "";
    string memberPassword = "";
    cout << "Please enter an email: " << endl;
    cin >> memberEmail;

    cout << "Please enter a password: " << endl;
    cin >> memberPassword;

}

int main(){
    initData();
    printMainMenu();
    int opt = 0;
    cin >> opt;

    if (opt == 1) 
    {
        printRegisterMemberHeader();
        registerMember();
    }

    else if (opt == 2) 
    {
        printAdminLoginHeader();
    }

    else if (opt == 3) 
    {
        printMemberLoginHeader();
    }

    else 
    {
        cout << "Please enter a valid input!" << endl;
        main();
    }
}

