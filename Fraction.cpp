#include "Fraction.h"

Fraction::Fraction(int n, int d){
    int g = gcd(n,d);
    //num = n;
    //den = d;    
    num = n/g;
    den = d/g;

}

Fraction& Fraction::operator=(const Fraction& f){
    num = f.num;
    den = f.den;
    return *this;
}


Fraction Fraction::operator++() {
    num += den;
    return *this;
}

Fraction Fraction::operator++(int){ //postfix
    Fraction f(num, den);
    num += den;
    return f;
}

bool Fraction::operator==(const Fraction& f) const{
    return num == f.num && den == f.den;
}

int Fraction::gcd(int n, int d){
    return d == 0 ? n : gcd(d, n % d);
} // Greatest common deviser


Fraction operator*(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.num * f2.num, f1.den * f2.den);
}


ostream& operator<<(ostream& out, const Fraction& f){
    out << f.num << '/' << f.den;
    return out;
}