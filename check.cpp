// #include <iostream>
// #include <conio.h>  // Include the conio.h library

// using namespace std;

// int main() {
//     char ch;

//     cout << "Press any key: ";
//     ch = getche();  // Waits for the user to press a key

//     cout << "\nYou pressed: " << ch << endl;

//     return 0;
// }
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to allow overriding in derived classes
    virtual void makeSound() {
        cout << "Some sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Overriding the base class method
    void makeSound() override {
        cout << "Woof" << endl;
    }
};

int main() {
    Animal* myAnimal = new Animal();
    Animal* mydog = new Dog();  // Base class pointer to a base class object
    mydog ->makeSound();
    myAnimal->makeSound();  // Output: Some sound
    
    delete myAnimal; 
    
    // delete myDog;
    return 0;
}
