#include <iostream>
#include <iomanip>

using namespace std;

void testPointers() {
    cout << "Hi!\n";
    int n, *p; // The type of p is int*
    n = 50;
    //p = n;
    p = &n;// Assigning the address of p to n
    cout << "n = " << n << " and p = " << p << " and *p is " << *p << endl;
    n = 21;
    cout << "n = " << n << " and p = " << p << " and *p is " << *p << endl;
    //p = (int*) 36;// Legal code but do not run this(if ur system programmer youll need smth like this)
    *p = 33;
    cout << "n = " << n << " and p = " << p << " and *p is " << *p << endl;
    p = new int;
    cout << "n = " << n << " and p = " << p << " and *p is " << *p << endl;
    *p = 76;
    cout << "n = " << n << " and &n is " << &n << " and p = " << p << " and *p is " << *p << endl;
    int *q = p;
    p = new int;
    *p = 30;
    cout << n << "  " << p << " " << *p << ' ' << *q << endl;
    delete p;
    p = nullptr; // NULL
    p = new int;
    cout << n << "  " << p << " " << *p << ' ' << *q << endl;
}

void testArray(){
    int a[5] = {1,2,3,4};
    int *p = new int[5]{10,20,30,40};
    cout << *p << ' '<< p[0] << ' '<< p[1] << ' ' << *p +1 << ' '<< *(p + 1) << endl;
    delete [] p; // Use square brakets when deleting array before the name of the array
    p = new int[7]{0,0};
}

int main() {
    //testPointers();
    testArray();
    return 0;
}