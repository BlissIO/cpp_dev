#include <iostream>
//Operator overloading
using namespace std;

class Fraction {
    public:
        Fraction(int n = 0, int d = 1){
            num = n;
            den = d;
        }
        Fraction operator*(const Fraction& f){
            return Fraction(num*f.num, den*f.den);
        }
    private:
        int num, den;
        // friend ostream& operator<<(ostream& out, const Fraction& f); Same as:
        friend ostream& operator<<(ostream&, const Fraction&);
        friend Fraction operator*(const Fraction&, const Fraction&);

};

Fraction operator*(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.num * f2.num, f1.den * f2.den);
}

ostream& operator<<(ostream& out, const Fraction& f){
    out << f.num << '/' << f.den;
    return out;
}
int main() {
    Fraction f1, f2(5), f3(6,7);
    //cout << f1.num << ' ' << f1.den << endl;
    //cout << f2.num << ' ' << f2.den << endl;
    //cout << f3.num << ' ' << f3.den << endl;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << f2*f3 << endl;
    cout << operator*(f2, f3) << endl;// for a non-member function
    //cout << f2.operator*(f3) << endl; // for a memeber func, they are both the same
    cout << f2*3 << endl;
    cout << 3*f2 << endl;
    f1 = f2*f3;
    cout << f1 << endl;
    return 0;
}
