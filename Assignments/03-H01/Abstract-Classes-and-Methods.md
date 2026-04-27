# Abstract Classes and Methods

> Classes that cannot be instantiated and must be implemented by derived classes.

---

## Definition

An **abstract class** is a class that cannot be instantiated — it exists only to be inherited. It may contain **pure virtual functions** (methods with `= 0`) that derived classes must implement. A class with at least one pure virtual function is automatically abstract.

```cpp
class Shape {                          // Abstract class
public:
    virtual double area() const = 0;   // Pure virtual — must be overridden
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

int main() {
    // Shape s;  // ERROR: cannot instantiate abstract class
    Circle c(5.0);  // OK
    Shape* ptr = &c;  // OK: pointer to base
    return 0;
}
```

---

## Why It Matters

Abstract classes define **interfaces** — a contract that derived classes must fulfill. They let you write code that works with any shape, any animal, any device without knowing the specific type.

---

## Common Mistakes

1. **Forgetting to implement all pure virtual functions** — Derived class also becomes abstract
2. **Trying to instantiate an abstract class** — Compilation error

---

## Related Concepts

- [Interfaces](./Interfaces)
- [Polymorphism](./Polymorphism)
- [Virtual Functions](./Virtual-Functions)

---

## Further Reading

- [Abstract classes (learncpp.com)](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-and-abstract-classes/)