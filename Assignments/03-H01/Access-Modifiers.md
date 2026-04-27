# Access Modifiers

> Keywords that control the visibility and accessibility of class members.

---

## Overview

**Access modifiers** (`public`, `private`, `protected`) define who can access a class's members. They are the primary mechanism for enforcing **encapsulation**.

| Modifier    | Same Class | Derived Class | Outside World |
| :--------- | :--------: | :-----------: | :-----------: |
| `public`   | ✅ Yes     | ✅ Yes        | ✅ Yes       |
| `protected`| ✅ Yes     | ✅ Yes        | ❌ No        |
| `private`  | ✅ Yes     | ❌ No        | ❌ No        |

---

## public

Members declared `public` are accessible from anywhere — inside the class, by derived classes, and from outside the class.

```cpp
class Student {
public:
    string name;      // Anyone can read/write
    void setGrade(int g) { grade = g; }
    int getGrade() { return grade; }

private:
    int grade;        // Only Student can access
};
```

---

## private

Members declared `private` are only accessible within the class itself. This is the strictest level of hiding.

```cpp
class BankAccount {
private:
    double balance;   // Hidden from everyone

public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
    }
};

int main() {
    BankAccount acc;
    acc.balance = 1000;  // ERROR: balance is private
    acc.deposit(500);     // OK: public method
}
```

---

## protected

Members declared `protected` are accessible within the class and by derived classes, but not from outside.

```cpp
class Shape {
protected:
    string color;  // Accessible by subclasses
};

class Circle : public Shape {
public:
    void setColor(string c) { color = c; }  // OK: derived class
};

int main() {
    Circle c;
    c.color = "red";  // ERROR: protected
}
```

---

## Why Access Modifiers Matter

1. **Encapsulation** — hide internal state, expose clean interface
2. **Validation** — control how data is modified (e.g., `deposit()` checks for positive amounts)
3. **Maintenance** — change internal implementation without breaking users
4. **Inheritance control** — decide what derived classes can access

---

## The `struct` Default

In C++, `struct` defaults to `public` member access, while `class` defaults to `private`. Otherwise they are identical.

```cpp
struct PointStruct { int x; int y; };  // x and y are public

class PointClass { int x; int y; };     // x and y are private
```
