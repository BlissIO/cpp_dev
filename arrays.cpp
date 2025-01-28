#include <iostream>

using namespace std;

void printArray(int* a, int sz) {
for( int i =0; i < sz; i++)
        cout << *(a + i) << ' ';
    cout << endl;

}

void printArray2(int* a, int sz) {
for( int i =0; i < sz; i++)
        cout << a[i] << ' ';
    cout << endl;

}

void printArray3(int* a, int sz) {
for( int i =0; i < sz; i++)
        cout << *a++ << ' ';
    cout << endl;

}

void f(int n, int& m) {// passing by value passing by refrence
    n = 21;
    m = 22;
    cout << "in f(): " << n << ' ' << m << endl;
}

void g(int *p1, int *p2, int*& p3){
    p1[0] = 32;
    p1[1] = 32;
    p2 = new int[2]{41,42};
    p3 = new int[2]{51,52};
    printArray(p2, 2);
    printArray(p3,2);
}

int main() {
    int a1[] = {1,2,3};
    int a2[4]{11,12,13,14};
    int* p = new int[5];
    /*printArray(a1,3);
    printArray(a2,4);
    printArray(p,5);
    printArray3(a1,3);*/

    int i1 = 11, i2 = 12;
    cout << "in main(): " << i1 << ' ' << i2 << endl;
    f(i1, i2);
    cout << "in main(): " << i1 << ' ' << i2 << endl;

    int* p3 = new int[3]{61,62,63};
    printArray(a1,3);
    printArray(p,3);
    printArray(p3,3);
    g(a1,p,p3);
    printArray(a1,3);
    printArray(p,3);
    printArray(p3,3);

    return 0;
}