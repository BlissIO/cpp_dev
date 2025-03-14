#include <iostream>
#include <vector>

using namespace std;

class A {
    public:
        int k = 1;
    protected:
        int m = 2;
    private:
        int n =3;
    public:
        void print() {
            cout << "k = " << k << " m = " << m << " n = " << n << endl;
        }
};
//class B : private A { // Same as:
class B : A {
    public:
        void print() {
            cout << "k = " << k << " m = " << m << endl;
        }
};

//template<typename T>
template<class T = int, int m = 123>
class C {
    public:
    T t;
    T a[10];
    T *p = new T[m];
    T f(T t, int n){
        T tt;
        tt = t;
        return tt;
    }
    void g(T t);
};

template<class T, int m>
void C<T,m>::g(T t) {
    cout << t;
}

void testTemplate() {
    C<int,55> c;
    c.g(33);
    C<> c2;
    c2.g(66);
}
/*
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for (int i = 0; i < v.size(); i++)
        out << v[i] << ' ';
    out << endl;
    return out;
}*/

template<class T>
ostream& operator<<(ostream& out, const vector<T>& v){
    typename vector<T>::const_iterator i = v.begin();
    for( ; i != v.end(); i++)
        out << *i << ' ';
    out << endl;
    return out;
}
void testVector() {
    vector <int> v;
    v.push_back(10);
    cout << v.at(0) << ' ' << v[1] << endl;
    cout << v << endl;
}
void testAccessibility() {
    A a;
    a.print();
    a.k = 11;
    //a.m = 12; // Protected data member cannot be accessed from the outside
    //a.n = 13; // Cannot access private data

    a.print();
    B b;
    b.print();
    //b.n = 21;
}

int main() {
    //testAccessibility();
    testVector();
    return 0;
}