# Instance Variables

> Variables that belong to a specific object (instance) of a class.

---

## Definition

**Instance variables** (also called **member variables** or **instance attributes**) are variables declared inside a class that belong to each individual object instance. Each object gets its own independent copy of these variables.

```cpp
class Student {
public:
    string name;       // Instance variable
    int id;            // Instance variable
    double gpa;        // Instance variable

    void print() const {
        cout << name << " (ID: " << id << ") — GPA: " << gpa << endl;
    }
};

int main() {
    Student s1, s2;
    s1.name = "Alice"; s1.id = 101; s1.gpa = 3.8;
    s2.name = "Bob";   s2.id = 102; s2.gpa = 3.5;
    s1.print();  // Alice (ID: 101) — GPA: 3.8
    s2.print();  // Bob   (ID: 102) — GPA: 3.5
    return 0;
}
```

---

## Why It Matters

Instance variables hold the **state** of each object. Without them, all objects of a class would behave identically — there'd be no distinction between two different Student objects.

---

## Common Mistakes

1. **Confusing instance variables with class variables** — Class variables (`static`) are shared across all instances; instance variables are per-object
2. **Accessing instance variables before initialization** — Leads to garbage values

---

## Related Concepts

- [Class Variables](./Class-Variables)
- [Classes and Objects](./Classes-and-Objects)
- [Member Variables](./Member-Variables)

---

## Further Reading

- [Class member variables (learncpp.com)](https://www.learncpp.com/cpp-tutorial/class-member-variables/)