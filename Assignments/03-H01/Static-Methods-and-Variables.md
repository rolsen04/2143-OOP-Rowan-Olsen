# Static Methods and Variables

> Functions and data that belong to the class itself, not to any instance.

---

## Definition

A **static method** is a member function that belongs to the class, not to any specific instance. It can be called without creating an object using `ClassName::method()`. Static methods cannot access non-static (instance) members directly.

```cpp
class MathUtils {
public:
    static int max(int a, int b) { return a > b ? a : b; }
    static double circleArea(double r) { return 3.14159 * r * r; }
    static int abs(int x) { return x >= 0 ? x : -x; }
};

int main() {
    int m = MathUtils::max(5, 3);           // No object needed
    double area = MathUtils::circleArea(2); // Class::method() syntax
    return 0;
}
```

---

## Why It Matters

Static methods are used for utility functions that don't need object state (like `Math::sqrt`, `String::format`). Static variables hold shared state (counters, config) across all instances.

---

## Common Mistakes

1. **Trying to access `this` in a static method** — `this` doesn't exist; there is no instance
2. **Confusing class variables with global variables** — Class variables still respect access modifiers

---

## Related Concepts

- [Class Variables](./Class-Variables)
- [Instance Variables](./Instance-Variables)
- [Methods](./Methods)

---

## Further Reading

- [Static members (learncpp.com)](https://www.learncpp.com/cpp-tutorial/static-member-functions/)