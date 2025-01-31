#include <iostream>
#include <cstring>

using namespace std;

int m =7;
struct S {
    int n = 5;
    char *s;
} s1, s2;

class C {
    public:
    int n = 8;
    char *s;
    C(const C&c){
        cout << "copy consturctor" << endl;
        n = c.n; // not necessary
        s= _strdup(c.s); //not s = c.s
    }
    C(int nn = 1, char *ss = _strdup("abc")) {
        n = nn;
        s = _strdup(ss);
        cout << "contructor " << this << endl;
    }
    //~C(){
    //   delete [] s;
    //}
    void f(int& a, const int& b) const {// the second const does not allow to modify data memebers
        //n = a;// the first const does not allow to modify argument(s)
        //b = n;
    }
    void print() {
        cout << n << ' ' << s << ' ' << (void*) s << ' ' << this << endl;
    }
};
void f(C c){
    c.n = 33;
    c.print();
}
void g(C&c){
    c.n = 44;
    c.print();
}
void testParameterPassing(){
    C c1(55,"ghi");
    C c2(66, "jkl");
    c1.print();
    c2.print();
    cout << "f():\n";
    f(c1);
    c1.print();
    cout << "g():\n";
    g(c2);
    c2.print();
}

void testClass(){
    int p = 11;
    C c;
    
}


void testCopyConstuctor() {
    C c1(21, _strdup("def"));
    C c2 = c1;
    c1.print();
    c2.print();
    c1.s[1] = 'X';
    c1.print();
    c2.print();

    C c3;
    c3 = c1;
    c3.s[1] ='Y';
    c1.print();
    c3.print();

}


int main() {
    /*S s;

    C c1, c2(123), c3(234,_strdup("pqr"));
    C *p1 = new C(67,strdup("XYZ"));

    cout << s.n << ' ' << c1.n << ' ' << c3.s << ' ' << c2.n << endl;
    cout << (*p1).n << endl;
    cout << p1->n << endl;*/
    //testCopyConstuctor();
    testParameterPassing();
    return 0;
}