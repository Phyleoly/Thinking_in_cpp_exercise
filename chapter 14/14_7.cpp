#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    int f() const {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const { return 1; }
    void g() {}
};

class Derived1 : public Base {
public:
    void g() const {}
};

class Derived2 : public Base {
public:
    int f() const {
        cout << "Derived2::f()\n";
        return 2;
    }
};

class Derived3 : public Base {
public:
    void f() const { cout << "Derived3::f()\n"; }
};

class Derived4 : public Base {
public:
    int f(int) const {
        cout << "Derived4::f(int)\n";
        return 4;
    }
};

int main() {
    string s("hello");
    Derived1 d1;
    int x = d1.f();
    d1.f(s);
    
    Derived2 d2;
    x = d2.f();
    // d2.f(s); 
    
    Derived3 d3;
    // x = d3.f(); 
    
    Derived4 d4;
    // x = d4.f(); 
    x = d4.f(1);

    return 0;
}