// homework_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*Tony Russell
* 01/18/2018
* CS201R

Found code for testing input on cplusplus.com*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int printMenu();
int menu(double balance);
void printBalance(double balance);
double withdraw(double balance);
double deposit(double balance);
double getLoan(double balance);

double bankBalance = 1000000;

int main()
{
    menu(bankBalance);
    return 0;
}

int printMenu()
{
    string menuLine = "============================================\n";
    int userSelection;
    bool input;
    do
    {
        cout << endl << menuLine << "Welcome to your bank!\n"
            << "Please select from the following menu items:\n"
            << menuLine << "1: Withdraw\n2: Deposit\n3: Balance inquiry\n"
            << "4: Apply for a loan\n5: Exit\n" << menuLine << endl;

        cin >> userSelection;
        input = cin.fail();

        cin.clear();
        cin.ignore();
    } while (input);

    return userSelection;
}

int menu(double balance)
{
    switch (printMenu())
    {
    case 1:
        balance = withdraw(balance);
        menu(balance);
    case 2:
        balance = deposit(balance);
        menu(balance);
    case 3:
        printBalance(balance);
        menu(balance);
    case 4:
        balance = getLoan(balance);
        printBalance(balance);
        menu(balance);
    case 5:
        exit(0);
    default:
        cout << "Invalid selection!\n";
        menu(balance);
    }
}

void printBalance(double balance)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "\nYour account balance is " << balance << endl;
}

double withdraw(double balance)
{
    double amt;
    cout << "How much would you like to withdraw?\n\n";
    cin >> amt;
    if (amt > balance)
    {
        cout << "\nYou cannot withdraw more than your account balance\n";
        withdraw(balance);
    }
    else
    {
        balance -= amt;
        cout << "\n$" << amt << " has been withdrawn from your account\n\n";
        printBalance(balance);
        return balance;
    }
}

double deposit(double balance)
{
    double amt;
    cout << "How much would you like to deposit?\n\n";
    cin >> amt;
    balance += amt;
    printBalance(balance);
    return balance;
}

double calcLoan(double amt, double interest, int months)
{
    double x = (amt * pow(1 + interest, (months / 12))) / months;
    cout << "Your monthly payment will be $" << x << endl;
    return x;
}

double getLoan(double balance)
{
    int creditScore, months;
    double loanAmt;

    cout << "\nHow much money would you like to borrow?\n\n";
    cin >> loanAmt;
    cout << "\nWhat is your credit score?\n\n";
    cin >> creditScore;
    cout << "\nHow many months will it take you to pay back this loan?\n\n";
    cin >> months;

    if (creditScore <= 500)
    {
        calcLoan(loanAmt, .05, months);
    }
    else if (creditScore > 700)
    {
        calcLoan(loanAmt, .01, months);
    }
    else
    {
        calcLoan(loanAmt, .02, months);
    }
    balance += loanAmt;
    return balance;
}