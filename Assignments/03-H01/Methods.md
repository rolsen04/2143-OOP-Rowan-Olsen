# Methods

> Functions defined inside a class that operate on the object's data.

---

## Definition

**Methods** (also called **member functions**) are functions defined inside a class that define the behavior of objects of that class. They have access to the object's `this` pointer and can read/modify the object's instance variables.

```cpp
class Stack {
private:
    vector<int> data;

public:
    void push(int val) { data.push_back(val); }
    void pop() { if (!empty()) data.pop_back(); }
    bool empty() const { return data.empty(); }
    int top() const { return data.back(); }
};
```

---

## Why It Matters

Methods encapsulate **behavior** associated with an object. They operate on instance data (encapsulation) and define what you can do with an object without knowing how it works internally.

---

## Common Mistakes

1. **Modifying the object when it shouldn't be modified** — Mark methods `const` when they don't change state
2. **Returning references to internal data** — Can break encapsulation; prefer returning copies or const references

---

## Related Concepts

- [Classes and Objects](./Classes-and-Objects)
- [Encapsulation](./Encapsulation)
- [Static Methods and Variables](./Static-Methods-and-Variables)

---

## Further Reading

- [Member functions (learncpp.com)](https://www.learncpp.com/cpp-tutorial/adding-member-functions/)