# Virtual Functions

> Functions marked `virtual` that can be overridden in derived classes for polymorphic behavior.

---

## Definition

A **virtual function** is a member function declared in a base class that a derived class can override. When you call a virtual function through a base class pointer or reference, C++ uses **dynamic dispatch** — the correct version is determined at runtime based on the actual object type.

```cpp
class Animal {
public:
    virtual void speak() const {
        cout << "Some sound" << endl;
    }
    virtual ~Animal() {}  // Virtual destructor for proper cleanup
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Animal();

    for (int i = 0; i < 3; i++) {
        animals[i]->speak();  // Calls correct version at runtime
    }
}
```

**Output:**
```
Woof!
Meow!
Some sound
```

---

## How It Works

When a class has virtual functions, C++ creates a **vtable** (virtual function table) for that class. Each object of that class holds a hidden **vptr** (virtual table pointer) to its class's vtable. When a virtual function is called, the program follows the vptr to find the correct function address.

```
Animal obj:    [vptr] → Animal::vtable → speak()
Dog obj:       [vptr] → Dog::vtable    → Dog::speak()
Cat obj:       [vptr] → Cat::vtable    → Cat::speak()
```

---

## `override` Keyword (C++11)

The `override` specifier explicitly tells the compiler that a derived class function is meant to override a base class virtual function. If the override doesn't actually override anything, the code fails to compile.

```cpp
class Dog : public Animal {
public:
    void speak() const override {  // Compiler checks: does Animal have this?
        cout << "Woof!" << endl;
    }
};
```

**Always use `override`** — it catches mistakes like a mismatched function signature.

---

## Virtual Destructor

If a base class has virtual functions, its destructor **must** be virtual. Otherwise, deleting a derived object through a base pointer only calls the base destructor.

```cpp
class Base {
public:
    virtual void foo() {}
    virtual ~Base() {}  // Virtual destructor
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Calls both ~Derived() and ~Base()
}
```

---

## Pure Virtual Functions

A pure virtual function has no implementation in the base class — derived classes **must** provide their own:

```cpp
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual = abstract
    virtual void print() const = 0;
};
```

A class with at least one pure virtual function is **abstract** and cannot be instantiated.
