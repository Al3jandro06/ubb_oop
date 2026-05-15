# ubb_oop

A collection of C++ Object-Oriented Programming laboratory projects developed at Babeș-Bolyai University. Each lab progressively builds on core OOP concepts, data structures, and software architecture patterns.

---

## Labs Overview

### Lab05 & Lab06 — Complex Numbers & Array Management

Two iterations of the same problem, demonstrating the evolution from a manual implementation to STL-based solutions.

| | Lab05 | Lab06 |
|---|---|---|
| **Storage** | Custom dynamic array | `std::vector` (STL) |
| **Data** | Complex numbers | Complex numbers |
| **Focus** | Manual memory management, OOP fundamentals | STL containers, cleaner abstractions |

**Key concepts:** classes, operator overloading, dynamic memory, STL

---

### Lab07-08 — Apartment Expense Manager

A fully layered C++ application for managing apartment expenses, built with a clean separation of concerns.

**Features**
- Add, update, and delete expense records
- Filter and display expenses by custom criteria
- Undo / Redo support for all operations

**Architecture**
```
UI Layer
   └── Service / Business Logic Layer
          └── Repository Layer (data storage)
```

**Key concepts:** layered architecture, OOP design, STL (`std::stack`, `std::vector`) for undo/redo

---

## Tech Stack

- **Language:** C++
- **Concepts:** OOP, dynamic memory, STL, layered architecture, undo/redo patterns

---

## Author

[Al3jandro06](https://github.com/Al3jandro06)
