# Method Overloading

> Defining multiple methods with the same name but different parameter types or counts.

---

## Definition

**Method overloading** (also called **function overloading**) allows multiple functions with the same name as long as they have different parameter signatures (different types, different counts, or different order). The compiler determines which version to call based on the arguments.

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    string add(string a, string b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    calc.add(1, 2);        // Calls int version
    calc.add(1.5, 2.5);    // Calls double version
    calc.add("Hi ", "Bob"); // Calls string version
    return 0;
}
```

---

## Why It Matters

Overloading lets you use the same intuitive name for conceptually similar operations. `add()` works for ints, doubles, and strings — you don't need `addInts`, `addDoubles`, etc.

---

## Common Mistakes

1. **Ambiguous calls** — If the compiler can't determine which overload to call, compilation fails
2. **Overloading when a different name is clearer** — Don't overload just to avoid new names

---

## Related Concepts

- [Operator Overloading](./Operator-Overloading)
- [Methods](./Methods)

---

## Further Reading

- [Function overloading (learncpp.com)](https://www.learncpp.com/cpp-tutorial/function-overloading/)