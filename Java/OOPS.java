    import pack.Account;

class Student {
    String name;
    int age;

    Student() {
        System.out.println("This is a non-parameterized constructor");
    }

    Student(String name, int age) {
        System.out.println("This is a parameterized constructor");
        this.name = name;
        this.age = age;
    }

    Student(Student s2) {
        System.out.println("This is a copy constructor");
        this.name = s2.name;
        this.age = s2.age;
    }

    // polymorphism - "function overloading"
    public void printInfo(String name) {
        System.out.println(name);
    }

    public void printInfo(int age) {
        System.out.println(age);
    }

    public void printInfo(String name, int age) {
        System.out.println(name + " " + age);
    }
}

/* inheritance - allowing new class to inherit prop & behavior of existing class
single level, multilevel, multiple, hierarchical */

class Shape {
    String color;

    public void area() {
        System.out.println("This prints area");
    }
}

class Triangle extends Shape { // single level - as triangle inherits shape
    int base, height;

    public void area(int base, int height) {
        System.out.println((int)(0.5 * base * height));
    }
}

class EquilateralTriangle extends Triangle { // multi-level - as equi. inherits triangle which inherits shape
    public void area(int base, int height) {
        System.out.println(color);
        System.out.println(0.5 * base * height);
    }
}

class Circle extends Shape { // hierarchical inheritance - Circle, Square, and Triangle are derived from Shape
    public void area(int radius) {
        System.out.println(3.14 * radius * radius);
    }
}

class Square extends Shape {
    public void area(int side) {
        System.out.println(side * side);
    }
}

// Access modifiers - Access modifiers control the visibility and accessibility of classes, methods, and variables.

class Accounts {
    // default - if you don't add anything of the 3 keyword by convention it takes that characteristic as default
    public String name; // this will be accessile to everyone
    protected String email; // would be accessible to derived classes and packages
    private String password; // only accessible withing the class, no object can access this

    // getter
    public String getPassword() {
        return this.password;
    }

    // setter
    public void setPassword(String pass) {
        this.password = pass;
    }
}

// abstraction
abstract class Animal {
    Animal() {
        System.out.println("You are creating a new animal");
    }

    abstract void walk();
    public void eat() {
        System.out.println("They be eating a lot");
    }
}

class Horse extends Animal {
    Horse() {
        System.out.println("Horse has been created.");
        System.out.println("This thing is called constructor chaining, when base class cons. is called before derived class's cons. when instantiating it");
    }

    public void walk() {
        System.out.println("Walks on 4 legs");
    }
}

class Chicken extends Animal {
    public void walk() {
        System.out.println("Walks on 2 legs");
    }
}

// interface - it is a blueprint. you just declare the things , you need to define those in child classes
interface Animals {
    int eye = 2; // by default it is public static final. 

    // public - accessible to all 
    // static - same eye shared to all instance on animal
    // final - final (const) no changes can be made now

    void walk(); // by default it is public abstract - public - accessible to all, abstract - hidden
}

// multiple inheritance using interface
interface Herbivore {
    void eat();
}

class Horses implements Animals, Herbivore { // you use implement when deriving instead of extends
    public void walk() {
        System.out.println("Horse walks on 100 legs");
    }

    public void eat() { // if you inherit two class then you have to define methods inside them into child class
        System.out.println("fun fact: they are herbivore but occasional carnivore if needed");
    }
}

public class OOPS {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Aayush";
        s1.age = 18;

        Student s2 = new Student("Hulk", 40);
        Student s3 = new Student(s2);

        // inheritance

        // single level
        Triangle t1 = new Triangle();
        t1.color = "red";
        t1.area(2, 3);

        // multi-level
        EquilateralTriangle et1 = new EquilateralTriangle();
        et1.color = "blue";
        et1.area(2, 8);

        // hierarchical
        Circle c = new Circle();
        c.area(20);
        Square sq = new Square();
        sq.area(10);

        // package
        Account a1 = new Account();
        a1.name = "customer1";
        a1.printInfo();

        // access modifiers
        Accounts acc1 = new Accounts();
        acc1.name = "Aayush";
        acc1.email = "aayushkumar.jha2001@gmail.com";
        // acc1.password = "69god"; // uncomment - you will see the error - password is not accessible
        acc1.setPassword("69god");
        String acc1kaPassword = acc1.getPassword();
        System.out.println(acc1kaPassword);

        // abstraction
        Horse horse = new Horse();
        horse.walk();
        horse.eat();

        // Animal animal = new Animal();
        // animal.walk(); // run time error , would not be able to create object of animal class because it is abstract class, just a blueprint

        // interface and multiple inheritance
        Horses h1 = new Horses();
        h1.eat();
        h1.walk();
    }
}