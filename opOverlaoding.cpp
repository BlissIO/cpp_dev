#include <iostream>
using namespace std;

class Comp {
    private:
        int num1;
        int num2;
    public:
        Comp(int x = 0, int y = 0){
            num1 = x;
            num2 = y;
        }
        Comp operator+(const Comp& obj){
            Comp num;
            num.num1 = num1 + obj.num1;
            
        }
};