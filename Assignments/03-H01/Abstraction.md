# Abstraction

> Hiding complex implementation details behind a simple interface.

---

## Definition

**Abstraction** is the principle of exposing only the essential features of an object while hiding the unnecessary complexity. Users interact with a simplified interface without needing to understand the internal workings.

```cpp
class CoffeeMachine {
private:
    int waterLevel;
    int coffeeBeans;
    double temperature;
    int pressure;

public:
    void makeCoffee() {
        heatWater();
        grindBeans();
        brew();
        // Internal complexity hidden from user
    }

private:
    void heatWater()  { /* ... */ }
    void grindBeans() { /* ... */ }
    void brew()       { /* ... */ }
};

int main() {
    CoffeeMachine cm;
    cm.makeCoffee();  // User only needs to know this
}
```

---

## Why It Matters

Abstraction reduces cognitive load — you don't need to understand every detail to use something. Like driving a car: you use the steering wheel and pedals without knowing how the engine works.

---

## Common Mistakes

1. **Over-abstracting** — Creating interfaces for everything leads to unnecessary complexity
2. **Under-abstracting** — Exposing too much internal state makes code fragile

---

## Related Concepts

- [Encapsulation](./Encapsulation)
- [Interfaces](./Interfaces)
- [Abstract Classes and Methods](./Abstract-Classes-and-Methods)

---

## Further Reading

- [Abstraction (oracle.com)](https://docs.oracle.com/javase/tutorial/java/concepts/)
- [Abstraction (learncpp.com)](https://www.learncpp.com/cpp-tutorial/abstraction/)