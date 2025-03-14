#include <iostream>
#include <list>

using namespace std;

list<string> Planes = {"Boeing 737", "Boeing 787", "Boeing 747"};
int main(){
    for (string plane:Planes) {
        cout << plane << endl;
    }
    cout << Planes.back() << endl; 
    cout << Planes.front() << endl;
    Planes.push_front("Boeing 777");
    Planes.push_back("Boeing 707");
    for (string plane:Planes) {
        cout << plane << endl;
    }
    cout << Planes.size() << endl;
    return 0;
}
