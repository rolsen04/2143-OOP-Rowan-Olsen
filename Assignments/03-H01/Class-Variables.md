# Class Variables

> Variables shared by all instances of a class — one copy, used by every object.

---

## Definition

A **class variable** (declared with the `static` keyword) is shared by all instances of a class. There is only one copy of a static member variable regardless of how many objects of the class exist.

```cpp
class Counter {
private:
    int instanceCount;     // Instance variable — one per object
    static int totalObjects;  // Class variable — shared by all objects

public:
    Counter() { instanceCount = ++totalObjects; }

    int getInstance() const { return instanceCount; }
    static int getTotal() { return totalObjects; }
};

int Counter::totalObjects = 0;  // Must be defined outside class

int main() {
    Counter c1, c2, c3;
    cout << c1.getInstance() << endl;  // 1
    cout << c2.getInstance() << endl;  // 2
    cout << Counter::getTotal() << endl;  // 3 — shared!
    return 0;
}
```

---

## Why It Matters

Use class variables when you need **shared state** across all instances — like a global counter, a configuration value, or a database connection pool.

---

## Common Mistakes

1. **Forgetting to define static member outside class** — Linker error
2. **Using class variables where instance variables make more sense** — Creates hidden coupling between objects

---

## Related Concepts

- [Instance Variables](./Instance-Variables)
- [Static Methods and Variables](./Static-Methods-and-Variables)
- [Constructors and Destructors](./Constructors-and-Destructors)

---

## Further Reading

- [Static member variables (learncpp.com)](https://www.learncpp.com/cpp-tutorial/static-member-variables/)