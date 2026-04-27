# File I/O

> Reading from and writing to files in C++ using `fstream`.

---

## Overview

C++ provides three main classes for file operations:
- `ifstream` — input file stream (reading)
- `ofstream` — output file stream (writing)
- `fstream` — file stream (both reading and writing)

All three are defined in `<fstream>`.

---

## Writing to a File

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");

    if (!outFile) {
        cerr << "Could not open file!" << endl;
        return 1;
    }

    outFile << "Name: Alice" << endl;
    outFile << "Age: 21" << endl;
    outFile << "GPA: 3.8" << endl;

    outFile.close();  // Optional — destructor closes automatically
    return 0;
}
```

---

## Reading from a File

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("data.txt");

    if (!inFile) {
        cerr << "Could not open file!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
```

---

## Reading with >> Operator

For space-separated values:

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inf("grades.txt");
    string name;
    double gpa;

    while (inf >> name >> gpa) {
        cout << name << ": " << gpa << endl;
    }
    return 0;
}
```

**grades.txt:**
```
Alice 3.8
Bob 3.5
Carol 3.9
```

---

## Appending to a File

Use `ios::app` to append instead of overwriting:

```cpp
ofstream outFile("log.txt", ios::app);
outFile << "New entry" << endl;
```

---

## Binary File I/O

For binary data, use `ios::binary`:

```cpp
struct Student {
    char name[50];
    int id;
    double gpa;
};

void writeStudent(ofstream& out, const Student& s) {
    out.write(reinterpret_cast<const char*>(&s), sizeof(Student));
}

void readStudent(ifstream& in, Student& s) {
    in.read(reinterpret_cast<char*>(&s), sizeof(Student));
}
```

---

## Checking File State

```cpp
ifstream inf("data.txt");
if (inf.fail()) {
    cerr << "Failed to open" << endl;
}

// After reading:
if (inf.eof()) {
    cout << "End of file reached" << endl;
}
```

---

## Using RAII (Recommended)

Modern C++ uses RAII — let the destructor handle closing:

```cpp
void processFile(const string& filename) {
    ifstream inf(filename);  // Opens file
    string line;
    while (getline(inf, line)) {
        // Process line
    }
}  // inf goes out of scope, file automatically closed
```
