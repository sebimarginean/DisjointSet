# Disjoint Set Management with Linked List and Tree Representation

## Overview

This C++ project implements disjoint set management using two distinct data structures: a linked list and a tree. The disjoint set data structure supports operations like making a new set, finding the representative of the set containing a specific element, and union operations to merge two sets. This implementation is particularly useful for algorithms that require partitioning of a set into disjoint subsets, such as Kruskal's Minimum Spanning Tree algorithm.

## Features

- **MakeSet**: Creates a new set with a single element.
- **FindSet**: Determines the representative of the set containing the given element.
- **Union**: Merges two disjoint sets into a single set.
- **ShowComponent**: Displays the elements of a set (for the linked list implementation).
- **Tree Representation**: Efficiently manage disjoint sets using a tree structure with path compression and union by rank.
- **Linked List Representation**: Manage disjoint sets using a simple linked list structure.

## How to Compile and Run

Ensure you have a C++ compiler that supports the C++11 standard or newer. You can compile the project using the following command:

```bash
g++ -std=c++11 main.cpp LinkedListElem.h TreeElem.h -o disjointSets
