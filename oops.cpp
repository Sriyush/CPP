#include <bits/stdc++.h>
using namespace std;

// class
class Student {
    public: // access modi.
        int age;
        string registerNo;

        // Student() {

        // }

        Student() {
            cout << "This is a constructor";
        }

        Student(int age) {
            cout << "this is param. cons." << endl;
        }


        void print() {
            cout << age << " " << registerNo << endl;
        }

        ~Student() {

        }
};

// OOPS
// encapsulation
class solution {
    int a, b; // data hiding
    public:
        int solve(int ans) { // information(implementation) hiding
            a = ans;
            return b = a/2;
        }
}; // bundling of data and methods together as a whole


// abstaraction - abstraction is often achieved using abstract classes and pure virtual functions. An abstract class is a class that cannot be instantiated directly and usually contains at least one pure virtual function.

class Shape {
protected:
    string color;

public:
    virtual void draw() = 0; // virtual function(abstract method)

    void setColor(string color) {
        this->color = color;
    }


    string getColor() {
        return color;
    }
};

class square : public Shape {
public:

    void draw() override {
        cout << "square color is this : " << color << endl;
    }
};

class circle: public Shape {
public:
    void draw() override {
        cout << "circle color is this : " << color << endl;
    }
};

// polymorphism
// compile time - overloading
// run-time - overriding in inheritence
class Dora {
public:
    void nobita(int a, int b) {

    }

    void nobita(int a, int b, int c) {

    }

    void nobita(string sizuka) {

    }
};

/*
    INHERITANCE - 

    Single inheritance - class A -> class B
    Multilevel inheritance - class A -> class B -> class C
    Multiple inheritance - class A, class B -> class C
    Hierarchical inheritance - class A -> B, class A -> C, class B -> D, class C -> E
    Hybrid inheritance - could be combination of everything
*/

class a {
public:
    void printA() {
        cout << "A" ;
    }
};

class b {
public: 
    void printB() {
        cout << "B" ;
    }
};

class sui: public a, public b { // public , protected, private
public:
    void print() {
        cout << "this";
    }
};

// virtual inheritance 
class one {
    public:
        int x = 10;
};

class two : virtual public one {
public:
    int y;
};

class three: virtual public one {
public:
    int z;
};


class anomaly : public two, public three {
public:
    int alpha;
};

int main() {
    Student aayush;
    aayush.age = 20;
    aayush.registerNo = "21BCE5764";
    aayush.print();

    solution s;
    cout << s.solve(10) << "/n";

    square sq;
    sq.setColor("black");
    sq.draw();

    circle c;
    c.setColor("white");
    c.draw();

    sui si;
    si.print();

    anomaly ano; // stack
    cout << ano.x;
    // cout << ano.two::x;

    return 0;
}