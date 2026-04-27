# Encapsulation

> Bundling data and methods together, restricting direct access to protect internal state.

---

## Definition

**Encapsulation** is the OOP principle of bundling data (attributes) and the methods that operate on that data into a single unit (a class), while restricting direct access to the internal state from outside the class.

In C++, this is achieved using **access modifiers**: `private` (default), `protected`, and `public`.

```cpp
class BankAccount {
private:
    double balance;  // Hidden from outside code

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;  // Controlled access only
        }
    }

    double getBalance() const {
        return balance;
    }
};
```

---

## Why It Matters

Encapsulation protects an object's internal state from being corrupted by outside code. By keeping attributes `private` and providing `public` getter/setter methods, you control how data is read and modified — enforcing invariants (e.g., "balance can never go negative").

---

## Common Mistakes

1. **Making everything public** — Defeats the purpose of encapsulation
2. **Providing unrestricted setters** — e.g., `setBalance(double)` without validation lets invalid states in

---

## Visual: Encapsulation Structure

```
┌─────────────────────────────────┐
│         BankAccount             │
│  ┌───────────────────────────┐  │
│  │   private:                │  │
│  │     double balance;       │  │
│  └───────────────────────────┘  │
│  ┌───────────────────────────┐  │
│  │   public:                 │  │
│  │     deposit()             │  │
│  │     getBalance()          │  │
│  └───────────────────────────┘  │
└─────────────────────────────────┘
```

---

## Related Concepts

- [Access Modifiers](./Access-Modifiers)
- [Classes and Objects](./Classes-and-Objects)
- [Information Hiding](./Information-Hiding)

---

## Further Reading

- [Encapsulation (learncpp.com)](https://www.learncpp.com/cpp-tutorial/encapsulation/)
- [Encapsulation (oracle.com)](https://docs.oracle.com/javase/tutorial/java/concepts/)