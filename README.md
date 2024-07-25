# Queue Data Structure Using Array in C++

This repository contains the implementation of a queue data structure using an array in C++. Queues are FIFO (First-In-First-Out) data structures, commonly used in various algorithms and system functions.

## Features

- **Fixed Size:** Uses a predefined maximum size for the stack.
- **FIFO Order:** Ensures first-in-first-out order of processing elements.
- **Efficient Operations:** Provides efficient push and pop operations.

# API Reference

- **arrayQueue(int initialcapacity = 10);**
- **~arrayQueue();**
- **bool empty() const;**
- **int size() const;**
- **T& front();**
- **T& back();**
- **void pop();**
- **void push(const T& theElement);**
