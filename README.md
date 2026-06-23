# 📦 C++ Templates Practice — Data Structures Library

A collection of **9 generic, header-only data structure implementations** in **C++** using **templates**, covering both linked-list-based and array-based variants for core structures.

---

## 🗂️ Implemented Data Structures

| Class | Description | Implementation |
|---|---|---|
| `clsMyStack` | Stack (LIFO) | Linked-list based |
| `clsMyStackArr` | Stack (LIFO) | Array based |
| `clsMyQueue` | Queue (FIFO) | Linked-list based |
| `clsMyQueueArr` | Queue (FIFO) | Array based |
| `clsDblLinkedList` | Doubly Linked List | Pointer based |
| `clsDynamicArray` | Resizable dynamic array | Heap allocated |
| `clsArray` | Fixed-size array wrapper | Stack allocated |
| `clsMatrix` | 2D Matrix | Template based |
| `clsVector` | Vector (similar to std::vector) | Dynamic allocation |

---

## 💡 Key Concepts Demonstrated

- **C++ Templates** — all structures are fully generic and type-safe (`template<class T>`)
- **OOP Design** — each structure is encapsulated in its own class with clean public APIs
- **Dual Implementations** — Stack and Queue implemented in both linked-list and array variants to compare memory layout and performance tradeoffs
- **Pointer & Memory Management** — manual `new`/`delete`, node linking, and pointer arithmetic
- **STL-like API Design** — methods mirror STL conventions (`push`, `pop`, `top`, `front`, `size`, `isEmpty`)

---

## 🚀 Usage

All structures are **header-only** — just include the file you need:

```cpp
#include "clsMyStack.h"
#include "clsMyQueue.h"
#include "clsDblLinkedList.h"

// Generic — works with any type
clsMyStack<int> intStack;
clsMyStack<string> strStack;

intStack.push(10);
intStack.push(20);
cout << intStack.top(); // 20
intStack.pop();

clsMyQueue<double> queue;
queue.push(3.14);
cout << queue.front(); // 3.14
```

---

## 📁 Project Structure

```
C-TemplatesPractice/
│
├── clsMyStack.h         # Stack — linked-list
├── clsMyStackArr.h      # Stack — array
├── clsMyQueue.h         # Queue — linked-list
├── clsMyQueueArr.h      # Queue — array
├── clsDblLinkedList.h   # Doubly Linked List
├── clsDynamicArray.h    # Dynamic resizable array
├── clsArray.h           # Fixed-size array
├── clsMatrix.h          # 2D Matrix
└── clsVector.h          # Vector
```

---

## 🛠️ Requirements

- C++11 or later
- Any C++ compiler (GCC, Clang, MSVC)
- No external dependencies

---

## 🎯 Purpose

This project was built to **deeply understand how STL containers work internally** — by implementing them from scratch using templates, raw pointers, and manual memory management — rather than just consuming them as black boxes.

---

## 👤 Author

**Mohammed Qazal**
[LinkedIn](https://www.linkedin.com/in/mohammed-qazal-dev) • [GitHub](https://github.com/MQazal)
