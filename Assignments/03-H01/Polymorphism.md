# Polymorphism

> One interface, many implementations — the ability of different objects to respond differently to the same message.

---

## Definition

**Polymorphism** (Greek: "many forms") allows objects of different classes to be treated as objects of a common base class, with each object responding to the same message (method call) in its own way. In C++, this is achieved through **virtual functions**.

```cpp
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w_, double h_) : w(w_), h(h_) {}
    double area() const override { return w * h; }
};

void printArea(const Shape& s) {
    cout << "Area: " << s.area() << endl;
}
```

---

## Why It Matters

Polymorphism lets you write code that operates on base class pointers/references while the actual derived class implementation is selected at runtime. This makes it easy to extend programs without modifying existing code (Open-Closed Principle).

---

## Common Mistakes

1. **Forgetting `virtual`** — Without it, the base class method is called instead of the derived version (slicing)
2. **Forgetting `override`** — Without it, a misspelled method name silently creates a new method instead of overriding

---

## Related Concepts

- [Virtual Functions](./Virtual-Functions)
- [Inheritance](./Inheritance)
- [Abstract Classes and Methods](./Abstract-Classes-and-Methods)

---

## Further Reading

- [Polymorphism (learncpp.com)](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
- [Polymorphism (cplusplus.com)](https://cplusplus.com/doc/polymorphism/)