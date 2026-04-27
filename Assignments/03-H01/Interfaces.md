# Interfaces

> A contract that defines what a class must do, without specifying how.

---

## Definition

An **interface** is a type that defines a set of method signatures without implementing them. In C++, interfaces are implemented using **abstract base classes** with all pure virtual functions. A class that implements an interface must provide implementations for all of its methods.

```cpp
// Interface (abstract class with only pure virtuals)
class Drawable {
public:
    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
    virtual ~Drawable() = default;
};

class Circle : public Drawable {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override { /* draw circle */ }
    void resize(double factor) override { radius *= factor; }
};

class Square : public Drawable {
    double side;
public:
    Square(double s) : side(s) {}
    void draw() const override { /* draw square */ }
    void resize(double factor) override { side *= factor; }
};

void renderAll(const vector<Drawable*>& items) {
    for (auto item : items) {
        item->draw();  // Works with any Drawable type
    }
}
```

---

## Why It Matters

Interfaces allow **plug-and-play** architectures. Code can work with any class that implements an interface without knowing the concrete type. This is the foundation for polymorphism and dependency inversion.

---

## Common Mistakes

1. **Adding implementation to an interface** — If all methods are pure virtual, keep it that way
2. **Confusing interfaces with abstract classes** — An interface is a special abstract class with only pure virtuals

---

## Related Concepts

- [Abstract Classes and Methods](./Abstract-Classes-and-Methods)
- [Polymorphism](./Polymorphism)
- [Abstraction](./Abstraction)

---

## Further Reading

- [Interfaces in C++ (isocpp.org)](https://isocpp.org/wiki/faq/interfaces)
- [Abstract classes (learncpp.com)](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-and-abstract-classes/)