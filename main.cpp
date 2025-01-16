
#include <iostream>
#include <iomanip>

using namespace std;

void checkFormatting() {
    double n = 12.34, m = 1.23456789, k = 12345678.9, p = 0.0000000003, q = 1234;
    cout << n << ' ' << m << ' ' << k << ' ' << p << ' ' << q << endl;
    //showpoint displays the decimal point and 6 digits in total;
    cout << showpoint << n << ' ' << m << ' ' << k << ' ' << p << ' ' << q << endl;
    // setprecision(3) by itself displays only 3 digits of each number;
    cout << setprecision(3) << "Setprecisoin alone :" << n << ' ' << m << ' ' << k << ' ' << p << ' ' << q << endl;
    // fixed by itself displays 6 digits after the decimal point;
    cout << fixed << "Fixed Alone        :" << n << ' ' << m << ' ' << k << ' ' << p << ' ' << q << endl;
    // Combine them all;
    cout << fixed << setprecision(2) << "Combining them all :" << n << ' ' << m << ' ' << k << ' ' << p << ' ' << q << endl;
    cout << setw(10) << n << ' ' << m << ' ' << k << ' ' << p << ' ' << setw(8) << q << endl;
}

void testIf(){
    bool b = true;
    cout << b << endl;
    b = false;
    cout << b << endl;
    b =123;
    cout << b << endl;
    b= -123;
    cout << b << endl;
    b = "abc";
    cout << b << endl;
    b = !"abc";
    cout << b << endl;
    int n = 5;
    if (n) // if n is not zero
        cout << "test1\n";
    if (!n)// if n is zero
        cout << "test2\n";
    if (n == 5)
        cout << "n is equal to 5\n";
}

int main() {
    checkFormatting();
    testIf();
    return 0;
}