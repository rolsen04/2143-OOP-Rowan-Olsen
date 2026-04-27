# Classes and Objects

> A class defines a blueprint; an object is an instance of that blueprint.

---

## Definition

A **class** is a user-defined data type that bundles **data (attributes)** and **behavior (methods)** into a single unit. An **object** is a specific instance of a class, created in memory with its own copy of the class's attributes.

```cpp
class Rectangle {
public:
    // Attributes
    double width;
    double height;

    // Behavior
    double area() {
        return width * height;
    }
};

int main() {
    Rectangle r;       // Object (instance of Rectangle)
    r.width = 5.0;
    r.height = 3.0;
    // r is an instance of the Rectangle class
    return 0;
}
```

---

## Why It Matters

Classes are the fundamental building block of OOP. They let you model real-world entities with both **state** (data) and **behavior** (functions). Without classes, you'd be managing scattered data and functions separately — hard to organize and maintain.

---

## Common Mistakes

1. **Confusing the class with an object** — Saying "the Rectangle object IS the class" (a class is a type, an object is a concrete instance)
2. **Forgetting to initialize attributes** — Creating an object with uninitialized values leads to garbage data

---

## Related Concepts

- [Instance Variables](./Instance-Variables)
- [Methods](./Methods)
- [Constructors and Destructors](./Constructors-and-Destructors)
- [Encapsulation](./Encapsulation)

---

## Further Reading

- [Classes and Objects (learncpp.com)](https://www.learncpp.com/cpp-tutorial/classes-and-objects/)
- [Thinking in Objects (oracle.com)](https://docs.oracle.com/javase/tutorial/java/concepts/)