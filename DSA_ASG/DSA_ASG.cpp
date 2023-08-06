// DSA_ASG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
using namespace std;

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
    cout << "+  (Enter 'x' to return to menu)  +" << endl;
    cout << "+---------------------------------+" << endl;
}
void printAdminLoginHeader() {
    cout << "+---------------------------------+" << endl;
    cout << "+         Login as Admin          +" << endl;
    cout << "+  (Enter 'x' to return to menu)  +" << endl;
    cout << "+---------------------------------+" << endl;
}

void printMemberLoginHeader() {
    cout << "+---------------------------------+" << endl;
    cout << "+        Login as Member          +" << endl;
    cout << "+  (Enter 'x' to return to menu)  +" << endl;
    cout << "+---------------------------------+" << endl;
}

void registerMember() {
    string memberEmail = "";
    string memberPassword = "";
    cout << "Please enter an email: " << endl;
    cin >> memberEmail;
    if (memberEmail == "x") {
        main();
    }
    cout << "Please enter a password: " << endl;
    cin >> memberPassword;
    if (memberPassword == "x") {
        main();
    }


}

int main(){
    printMainMenu();
    int opt = 0;
    cin >> opt;

    if (opt == 1) 
    {
        printRegisterMemberHeader();

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

