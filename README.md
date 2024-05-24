
# Graph Operator Overloading 

## Overview

This part of the assignment involves implementing and testing several operator overloads for the `Graph` class. The goal is to extend the functionality of the `Graph` class by allowing graph instances to be compared, incremented, and manipulated using standard operators.

## Implemented Operators

### 1. Equality Operators
- **`bool operator==(const Graph &g) const`**: Checks if two graphs are equal.
- **`bool operator!=(const Graph &g) const`**: Checks if two graphs are not equal.

### 2. Comparison Operators
- **`bool operator>(const Graph &g) const`**: Checks if one graph is greater than another based on the criteria provided.
- **`bool operator<(const Graph &g) const`**: Checks if one graph is less than another based on the criteria provided.
- **`bool operator>=(const Graph &g) const`**: Checks if one graph is greater than or equal to another.
- **`bool operator<=(const Graph &g) const`**: Checks if one graph is less than or equal to another.

### 3. Increment/Decrement Operators
- **`Graph &operator++()`**: Pre-increment operator to increment all non-diagonal elements by 1.
- **`Graph operator++(int)`**: Post-increment operator to increment all non-diagonal elements by 1.
- **`Graph &operator--()`**: Pre-decrement operator to decrement all non-diagonal elements by 1.
- **`Graph operator--(int)`**: Post-decrement operator to decrement all non-diagonal elements by 1.

### 4. Arithmetic Operators
- **`Graph operator+(const Graph &g) const`**: Adds two graphs.
- **`Graph &operator+=(const Graph &g)`**: Adds another graph to the current graph.
- **`Graph operator*(int scalar) const`**: Multiplies all edge weights by a scalar.
- **`Graph &operator*=(int scalar)`**: Multiplies all edge weights by a scalar and updates the current graph.
- **`Graph operator*(const Graph &other) const`**: Multiplies two graphs using matrix multiplication.

## Files

### 1. `Graph.cpp`
Contains the implementation of the `Graph` class and all the operator overloads.

### 2. `Graph.hpp`
Header file for the `Graph` class. It includes declarations for the class methods and operators.

### 3. `Algorithms.cpp`
Provides additional algorithms and helper functions used within the `Graph` class and its operators.

### 4. `Algorithms.hpp`
Header file for the algorithms. It includes declarations for the helper functions used in `Algorithms.cpp`.

### 5. `doctest.cpp`
Includes the `doctest` framework for unit testing the implemented operator overloads.

### 6. `test.cpp`
Includes test cases for all the operator overloads implemented in the `Graph` class. The tests are written using the `doctest` framework.

### 7. Demo.cpp
A demonstration program showcasing the use of the implemented operator overloads for the Graph class.

## Test Cases

The tests for these operators are implemented using the `doctest` framework. They are located in the `test.cpp` file and cover all the operator overloads. The tests ensure that the operators work correctly for various scenarios, including equality, comparison, increment/decrement, and arithmetic operations.
