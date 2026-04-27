# OOP Wiki

### Rowan Olsen

### CMPS 2143 Dr. Griffin

### Date: May 8, 2026

---

## Description

This wiki covers the core concepts of Object-Oriented Programming (OOP) in C++. Each topic includes detailed explanations, practical C++ code examples, and visual aids to help understand OOP principles.

### Topics Covered

| # | Topic | Description |
|---|-------|-------------|
| 1 | [Home](./Home.md) | Wiki overview and navigation |
| 2 | [Classes and Objects](./Classes-and-Objects.md) | Building blocks of OOP |
| 3 | [Encapsulation](./Encapsulation.md) | Data hiding and bundling |
| 4 | [Inheritance](./Inheritance.md) | Passing down traits between classes |
| 5 | [Polymorphism](./Polymorphism.md) | One name, many forms |
| 6 | [Abstraction](./Abstraction.md) | Hiding complexity |
| 7 | [Constructors and Destructors](./Constructors-and-Destructors.md) | Object lifecycle management |
| 8 | [Access Modifiers](./Access-Modifiers.md) | public, private, protected |
| 9 | [Instance Variables](./Instance-Variables.md) | Per-object data |
| 10 | [Class Variables](./Class-Variables.md) | Shared data across objects |
| 11 | [Methods](./Methods.md) | Behavior defined in classes |
| 12 | [Static Methods and Variables](./Static-Methods-and-Variables.md) | Class-level members |
| 13 | [Virtual Functions](./Virtual-Functions.md) | Runtime polymorphism |
| 14 | [Abstract Classes and Methods](./Abstract-Classes-and-Methods.md) | Pure virtual functions |
| 15 | [Interfaces](./Interfaces.md) | Pure abstraction contract |
| 16 | [Operator Overloading](./Operator-Overloading.md) | Redefining operators for custom types |
| 17 | [Method Overloading](./Method-Overloading.md) | Multiple functions with same name |
| 18 | [References](./References.md) | Aliases to variables |
| 19 | [File I/O](./File-IO.md) | Reading and writing files in C++ |
| 20 | [Glossary](./Glossary.md) | OOP terms and definitions |
| 21 | [Changelog](./Changelog.md) | History of updates |

---

## How to Navigate

Click any topic in the table above or use the sidebar to browse. Each page includes:

- **Definition** of the concept
- **C++ code examples** tested and verified
- **Real-world analogies** to make it relatable
- **Key takeaways** at the end of each topic

---

## Building and Testing Code

All C++ code examples in this wiki are tested using the slave-coder fixer:

```bash
python /home/workspace/Skills/slave-coder/scripts/fixer.py <filepath> --check-only
```

To compile any example manually:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic <filepath> -o output
```