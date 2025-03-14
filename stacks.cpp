#include <iostream>
#include <stack>

using namespace std;

stack<string> mag;


int main(){
    mag.push("9mm Round");
    mag.push("10mm Round");
    mag.push("45mm Round");
    cout << mag.top() << endl;
    mag.top() = "308 Round";
    cout << mag.top() << endl;
    return 0;
}