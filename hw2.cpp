#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int *pint;
    pint = new int;
    if (pint == NULL)
        *pint = 100;
    else
        cout << "Memory allocation error\n";
}