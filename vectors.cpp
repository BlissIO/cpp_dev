#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<string> names = {"Jack", "Jimmy"};
    names.push_back("Jhon");

    for (string name : names) {
    cout << name << "\n";
    }

    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    cars.push_back("Tesla(Shitbucket)");

    for (string car : cars) {
    cout << car << "\n";
    }
    cars.pop_back();
    for (string car : cars) {
        cout << car << "\n";
    }
    cout << "see the Tesla is gone gone!";
    return 0;
}
