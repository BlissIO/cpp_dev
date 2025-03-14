#include <iostream>

using namespace std;

class IntegerSet {
    private:

        bool* a;
        int size;

    public:
        IntegerSet(int n){
            size = n + 1;
            a = new bool[size];
            for (int i = 0; i <  size; i++){
                a[i] = false;
            }
        }
    

};

int main(){

}