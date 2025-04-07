# C++ OOP Roadmap

## Table of Contents

1. [Introduction](#introduction)
2. [Phase 1: Introduction to Classes and Objects](#phase-1-introduction-to-classes-and-objects)
    - [Exercise 0: Basic Class and Object Creation](#exercise-0-basic-class-and-object-creation)
    - [Exercise 1: Setting and Getting Attributes](#exercise-1-setting-and-getting-attributes)
    - [Exercise 2: Constructors](#exercise-2-constructors)
    - [Exercise 3: Destructor](#exercise-3-destructor)
3. [Phase 2: Encapsulation and Access Control](#phase-2-encapsulation-and-access-control)
    - [Exercise 4: Getters and Setters](#exercise-4-getters-and-setters)
    - [Exercise 5: Constant Member Functions](#exercise-5-constant-member-functions)
4. [Phase 3: Inheritance and Polymorphism](#phase-3-inheritance-and-polymorphism)
    - [Exercise 6: Basic Inheritance](#exercise-6-basic-inheritance)
    - [Exercise 7: Polymorphism](#exercise-7-polymorphism)
5. [Phase 4: Operator Overloading and Advanced OOP Features](#phase-4-operator-overloading-and-advanced-oop-features)
    - [Exercise 8: Operator Overloading](#exercise-8-operator-overloading)
    - [Exercise 9: Friend Functions](#exercise-9-friend-functions)
    - [Exercise 10: Abstract Classes](#exercise-10-abstract-classes)
6. [Phase 5: Memory Management and Dynamic Polymorphism](#phase-5-memory-management-and-dynamic-polymorphism)
    - [Exercise 11: Memory Management](#exercise-11-memory-management)
    - [Exercise 12: Smart Pointers](#exercise-12-smart-pointers)

---

## Introduction

This roadmap is designed to guide you through the essential concepts of **Object-Oriented Programming (OOP)** in **C++**. Each phase introduces new topics, from basic class creation to advanced features like operator overloading, inheritance, polymorphism, and memory management.

By the end of this roadmap, you will have a strong understanding of how to apply **OOP principles** in C++ and how to write efficient, maintainable code.

---

## Phase 1: Introduction to Classes and Objects

### Goal:
- Understand how to define and use classes and objects in C++.
- Learn how to define attributes and methods within a class.

### Key Concepts:
- **Class**: A blueprint for creating objects (instances).
- **Object**: An instance of a class.
- **Public/Private**: Access specifiers used to control access to class members.

### Key Learning Outcomes:
- Basic class creation and object instantiation.
- Initialization of attributes and use of methods.

---

### Exercise 0: Basic Class and Object Creation

**Objective:**
- Create a simple `Person` class with attributes like `Name` and `Age`.
- Initialize the attributes directly in the `main` function.

**Instructions:**
1. Define a `Person` class with public attributes `Name` and `Age`.
2. In the `main` function, create an object `p1` of the `Person` class.
3. Assign values to `p1.Name` and `p1.Age` and print them.

```cpp
#include <iostream>
//
using namespace std;
//
class Person {
    public:
        string Name;
        int Age;
};
//
int main() {
    Person p1;
    //
    p1.Name = "Bob";
    p1.Age = 31;
    //
    cout << "Name: " << p1.Name << "\nAge: " << p1.Age;
    //
    return 0;
}
```

---

### Exercise 1: Setting and Getting Attributes

**Objective:**
- Create a method to set data for a `Person` and print it.

**Instructions:**
1. Add private access specifiers for `Name` and `Age` in the `Person` class.
2. Create a public method `setData()` to assign values to `Name` and `Age`.
3. Create a public method `printPerson()` to print the `Name` and `Age`.
4. In the `main` function, use the `setData()` method to assign values and then call `printPerson()` to display the data.

```cpp
#include <iostream>
//
using namespace std;
//
class Person {
    private:
        string Name;
        int Age;
    //
    public:
        void setData(string personName, int personAge) {
            Name = personName;
            Age = personAge;
        }
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age;
        }
};
//
int main() {
    Person p1;
    //
    p1.setData("Bob", 31);
    p1.printPerson();
    //
    return 0;

```

---

### Exercise 2: Constructors

**Objective:**
- Learn how to use constructors to initialize objects.

**Instructions:**
1. Modify the `Person` class to include a constructor that takes parameters for `Name` and `Age`.
2. In the constructor, initialize `Name` and `Age` with the given parameters.
3. In the `main` function, create objects of `Person` using both the default and parameterized constructors.

```cpp
#include <iostream>
//
using namespace std;
//
class Person {
    private:
        string Name;
        int Age;
    //
    public:
        Person(string defName = "Unknown", int defAge = 0) : Name(defName), Age(defAge) {}
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age << "\n";
        }
};
//
int main() {
    Person p1;
    Person p2("Bob", 31);
    //
    p1.printPerson();
    p2.printPerson();
    //
    return 0;
}
```

---

### Exercise 3: Destructor

**Objective:**
- Learn how to define and use destructors to clean up resources when an object is destroyed.

**Instructions:**
1. Define a destructor in the `Person` class.
2. Have the destructor output a message indicating that the `Person` object is being destroyed.
3. In the `main` function, create a `Person` object and let it go out of scope to trigger the destructor.

```cpp
#include <iostream>
//
using namespace std;
//
class Person {
    private:
        string Name;
        int Age;
    //
    public:
        Person(string defName = "Unknown", int defAge = 0) : Name(defName), Age(defAge) {}
        //
        ~Person() {
            cout << "Nooooooooooo, you monster.\nYOU DESTROYED " << Name;
        }
        //
        void printPerson() {
            cout << "Name: " << Name << "\nAge: " << Age << "\n";
        }
};
//
int main() {
    Person p1("Bob", 31);
    //
    p1.printPerson();
    //
    return 0;
}
```

---

## Phase 2: Encapsulation and Access Control

### Goal:
- Explore the concept of **Encapsulation** and how it relates to **access control** in C++.
- Understand how to properly use **getters** and **setters** to manage object state.

### Key Concepts:
- **Private/Protected/Public Members**: How access control affects data encapsulation.
- **Getters/Setters**: Methods used to access or modify private data.

### Key Learning Outcomes:
- Better understanding of data protection and class integrity.

---

### Exercise 4: Getters and Setters

**Objective:**
- Implement getters and setters for accessing and modifying the `Name` and `Age` attributes.
- Ensure that the `Age` cannot be set to a negative number.

```cpp

```

---

### Exercise 5: Constant Member Functions

**Objective:**
- Understand how to use `const` with member functions to make them read-only.

```cpp

```

---

## Phase 3: Inheritance and Polymorphism

### Goal:
- Learn how to use **Inheritance** to create class hierarchies.
- Explore **Polymorphism** to create flexible code that works with different types.

### Key Concepts:
- **Inheritance**: Deriving new classes from existing ones.
- **Polymorphism**: Using base class pointers or references to work with objects of derived classes.
- **Virtual Functions**: Functions that can be overridden in derived classes.

### Key Learning Outcomes:
- Learn how to extend functionality using inheritance.
- Understand how polymorphism allows you to interact with different object types.

---

### Exercise 6: Basic Inheritance

**Objective:**
- Create a base class `Person` and a derived class `Employee`.
- `Employee` should inherit from `Person` and have additional attributes such as `Salary`.

```cpp

```

---

### Exercise 7: Polymorphism

**Objective:**
- Use polymorphism to allow different derived classes to be handled in the same way through base class pointers or references.
- Override a base class method in the derived class and invoke it using a base class pointer.

```cpp

```

---

## Phase 4: Operator Overloading and Advanced OOP Features

### Goal:
- Understand how to overload operators in C++ to create custom behavior for basic operators (like `+`, `-`, `==`, etc.).
- Explore advanced topics like **friend functions** and **abstract classes**.

### Key Concepts:
- **Operator Overloading**: Customizing the behavior of operators for user-defined types.
- **Friend Functions**: Functions that can access private and protected members of a class.
- **Abstract Classes**: Classes that cannot be instantiated but can be used as base classes for other classes.

### Key Learning Outcomes:
- Ability to define custom operator behavior.
- Understanding of abstract classes and their use in C++.

---

### Exercise 8: Operator Overloading

**Objective:**
- Overload operators like `+` and `==` for custom classes to allow intuitive operations.

```cpp

```

---

### Exercise 9: Friend Functions

**Objective:**
- Implement a `friend` function that has access to private and protected members of a class.

```cpp

```

---

### Exercise 10: Abstract Classes

**Objective:**
- Create an abstract base class with pure virtual functions.
- Derive classes from the abstract class and implement the pure virtual functions.

```cpp

```

---

## Phase 5: Memory Management and Dynamic Polymorphism

### Goal:
- Understand how C++ handles memory management, including dynamic allocation and deallocation.
- Learn about **smart pointers** and their role in memory management.

### Key Concepts:
- **Dynamic Memory Allocation**: Using `new` and `delete` to manage memory manually.
- **Smart Pointers**: Automatically managing memory through `unique_ptr`, `shared_ptr`, etc.

### Key Learning Outcomes:
- Learn the importance of managing memory and preventing memory leaks.
- Understand dynamic polymorphism through virtual functions.

---

### Exercise 11: Memory Management

**Objective:**
- Allocate and deallocate memory dynamically using `new` and `delete`.

```cpp

```

---

### Exercise 12: Smart Pointers

**Objective:**
- Use `unique_ptr` and `shared_ptr` for automatic memory management to avoid manual `delete`.

```cpp

```

