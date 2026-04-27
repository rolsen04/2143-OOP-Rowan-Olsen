# Constructors and Destructors

> Special member functions that initialize and clean up objects.

---

## Definition

A **constructor** is a special method called automatically when an object is created, used to initialize the object's state. A **destructor** is called when an object is destroyed, used to release resources (e.g., dynamic memory, file handles).

```cpp
class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // Constructor
    DynamicArray(size_t s) : size(s), data(new int[s]) {
        cout << "Constructor called\n";
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;  // Free dynamic memory
        cout << "Destructor called\n";
    }
};

int main() {
    DynamicArray arr(10);  // Constructor called
    return 0;
}  // Destructor called automatically
```

---

## Why It Matters

Constructors ensure objects start in a **valid state**. Destructors ensure resources are **cleaned up** when an object is destroyed — critical for preventing memory leaks. In C++, RAII (Resource Acquisition Is Initialization) ties resource lifetime to object lifetime.

---

## Common Mistakes

1. **Missing destructor** — Causes memory leaks for classes with `new`/`delete`
2. **Using uninitialized pointers** — Dereferencing a null/wild pointer crashes the program
3. **Shallow copies on raw pointers** — Need custom copy constructor/assignment operator for dynamic data

---

## Constructor Types

```cpp
class MyClass {
public:
    int value;

    MyClass() : value(0) {}                       // Default
    MyClass(int v) : value(v) {}                 // Parameterized
    MyClass(const MyClass& other) : value(other.value) {}  // Copy
};
```

---

## Related Concepts

- [Classes and Objects](./Classes-and-Objects)
- [Memory Management](./Memory-Management)
- [Smart Pointers](./Smart-Pointers)
- [Copy Constructors](./Copy-Constructors)

---

## Further Reading

- [Constructors and Destructors (learncpp.com)](https://www.learncpp.com/cpp-tutorial/constructors/)
- [RAII (cpp.com)](https://cpp.com/doc/raii/)