# Operator Overloading

> Giving operators like `+`, `-`, `<<` custom behavior for user-defined types.

---

## Definition

**Operator overloading** lets you define how built-in operators (like `+`, `==`, `<<`, `[]`) behave when used with your class. This makes user-defined types feel natural, like built-in types.

```cpp
class Vec2 {
public:
    double x, y;

    Vec2(double x_, double y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }
};

ostream& operator<<(ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vec2 a(1.0, 2.0), b(3.0, 4.0);
    Vec2 c = a + b;          // (4.0, 6.0)
    cout << (a == b) << endl; // 0 (false)
    cout << c << endl;        // (4.0, 6.0)
    return 0;
}
```

---

## Why It Matters

Operator overloading makes classes expressive and intuitive. `a + b` reads more naturally than `a.add(b)` for mathematical types like vectors, complex numbers, or matrices.

---

## Common Mistakes

1. **Changing operator meaning in confusing ways** — `+` should add, not subtract
2. **Forgetting to return by value** — Chain expressions like `a + b + c` won't work

---

## Related Concepts

- [Method Overloading](./Method-Overloading)
- [Classes and Objects](./Classes-and-Objects)

---

## Further Reading

- [Operator overloading (learncpp.com)](https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators/)
- [C++ Operator Overloading (cplusplus.com)](https://cplusplus.com/doc/tutorial/functions2/)