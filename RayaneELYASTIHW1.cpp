//*******************************************************************
// Rayane EL YASTI
// Homework 1
// due 1/21/2025
// This program computes how many months it takes to pay off a loan
// and the amount of interest paid in total and also if the monthly
// payment is too low and if the inputs are negative
//*******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // declaring the needed variables as a double
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

    // Input validation
    if (loan <= 0 || yearInt <= 0 || monthPayment <= 0) {
        cout << "The input is invalid please provide positive values for all inputs.\n";
        return 1;
    }

    // Calculate the monthly interest rate
    double monthlyIntRate = (yearInt / 12) / 100;

    // Calculate minimum payment needed
    double minPayment = loan * monthlyIntRate;
    if (monthPayment <= minPayment) {
        cout << "Monthly payment is too low to cover the interest. Minimum payment needed: $" 
             << fixed << setprecision(2) << minPayment + 0.01 << endl;
        return 1;
    }

    // A loop that goes through every month until the loan is > 0
    while (loan > 0) {
        monthlyInt = loan * monthlyIntRate;
        // Adding the monthly interest to the total interest
        totalInt += monthlyInt;
        // Calculating the amount of money that is going to 
        // be taken off the loan and taking it off the loan
        double payNow = monthPayment - monthlyInt;
        loan -= payNow;
        // Keeping in mind the count of months
        monthCount++;
    }

    // Printing out the results
    cout << "It will take " << monthCount << " months to pay off the loan.\n";
    cout << fixed << setprecision(2) << "You will have to pay $" << totalInt << " in interest." << endl;    

    return 0;
}