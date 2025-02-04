//*******************************************************************
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

    // Asking the user for the loan amount, the interest rate,
    // and the monthly pay amount
    cout << "Please input the loan amount:\n";
    cin >> loan;
    cout << "Please input yearly interest rate:\n";
    cin >> yearInt;
    cout << "Please input Monthly payment amount:\n";
    cin >> monthPayment;
    // Calculate the monthly interest rate
    double monthInt = (yearInt / 12)/100;
    // A lop that goes through every month untill the loan is > 0
    while (loan >  0)
    {
        monthlyInt = loan * monthInt;
        // Adding the monthly interest to the total interest
        totalInt += monthlyInt;
        // Calculating the amount of money that is going to 
        // be taken off the loan and taking it off the loan
        double payNow = monthPayment - monthlyInt;
        loan -= payNow;
        // Keeping in mind the count of months
        monthCount ++;

    }
    // Printing out the results
    cout << "It will take " << monthCount << " months to pay off the loan.";
    cout << fixed << setprecision(2) << "You will have to pay " << totalInt << "$ in interest.";    

}