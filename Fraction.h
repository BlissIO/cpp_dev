#include <iostream>
//Operator overloading
using namespace std;

class Fraction {
    public:
        Fraction(int n = 0, int d = 1);
        //Fraction(int n = 0, int d = 1){
        //    num = n;
        //    den = d;
        //}

        //Fraction operator*(const Fraction& f){
        //    return Fraction(num*f.num, den*f.den);
        //}
        Fraction operator++();//prefix
        Fraction operator++(int);//postfix  
        bool operator==(const Fraction& f) const;
        Fraction& operator=(const Fraction& f);// Returns *this after assignment


    private:
        int num, den;


        // friend ostream& operator<<(ostream& out, const Fraction& f); Same as:

        friend ostream& operator<<(ostream&, const Fraction&);
        friend Fraction operator*(const Fraction&, const Fraction&);
        int gcd(int, int); // Greatest common deviser

};