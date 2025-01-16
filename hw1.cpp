//*******************************************************************
// Rayane EL YASTI
// Homework 1
// due 1/21/2025
// This program computes how many months it takes to pay off a loan
// and the amount of interest paid in total
//*******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // deaclaring the needed variables as a double
    double loan, yearInt, monthPayment, monthCount, monthlyInt, totalInt;
    // setting our month count and total 
    monthCount = 0;
    totalInt = 0;
    cout << "Please input the loan amount:\n";
    cin >> loan;
    cout << "Please input yearly interest rate:\n";
    cin >> yearInt;
    cout << "Please input Monthly payment amount:\n";
    cin >> monthPayment;
    double monthInt = (yearInt / 12)/100;
    while (loan >  0)
    {
        monthlyInt = loan * monthInt;
        totalInt += monthlyInt;
        double payNow = monthPayment - monthlyInt;
        loan -= payNow;

        monthCount ++;

    }

    cout << "It will take " << monthCount << " months to pay off the loan.";
    cout << fixed << setprecision(4) << "You will have to pay " << totalInt << "$ in interest.";    

}