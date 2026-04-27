# Inheritance

> Deriving new classes from existing ones to reuse and extend behavior.

---

## Definition

**Inheritance** allows a class (called a **derived class** or **child class**) to inherit attributes and methods from another class (called a **base class** or **parent class**), promoting code reuse and establishing an "is-a" relationship.

```cpp
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}
    void speak() const { std::cout << name << " makes a sound.\n"; }
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    Dog(const std::string& n) : Animal(n) {}
    void speak() const { std::cout << name << " barks: Woof!\n"; }
};
```

---

## Why It Matters

Inheritance lets you model "is-a" relationships (a Dog IS an Animal) and reuse common behavior defined in the parent class. The derived class adds or overrides behavior without rewriting the parent's logic.

---

## Common Mistakes

1. **Overusing inheritance (deep hierarchies)** — Leads to fragile code; prefer composition when possible
2. **Confusing "has-a" vs "is-a"** — If it doesn't truly model an "is-a" relationship, inheritance may be wrong

---

## Visual: Inheritance Hierarchy

```
         Animal
        /      \
    Dog        Cat
   /  \        / \
Pug  Beagle  Siamese Persian
```

---

## Related Concepts

- [Polymorphism](./Polymorphism)
- [Composition vs Aggregation](./Composition-vs-Aggregation)
- [Virtual Functions](./Virtual-Functions)
- [Abstract Classes and Methods](./Abstract-Classes-and-Methods)

---

## Further Reading

- [Inheritance (learncpp.com)](https://www.learncpp.com/cpp-tutorial/inheritance/)
- [Inheritance (cplusplus.com)](https://cplusplus.com/doc/tutorial/inheritance/)