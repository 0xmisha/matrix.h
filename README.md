# Matrix Library Implementation Summary

## Overview

The project revolved around the construction of a dedicated library, named `matrix.h`, for performing operations on numerical matrices using the C programming language. Matrices hold a fundamental position in programming, serving functions from representing data in tabular form to being core elements in computational tasks, including neural networks.

## Installation
````
git clone https://github.com/0xmisha/matrix.h.git
cd matrix.h/src
make
````

## Requirements

- Gcc
- Make
- check.h (for tests)

## Technical Specificities

### Data Structure

A structure `matrix_t` was designed to represent matrices:
```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

This structure includes a double pointer to represent the matrix and two integers specifying its dimensions.

### Core Functions

Several vital matrix operations were implemented:

1. **Creation**: `create_matrix` initializes a matrix with specified rows and columns.
2. **Deletion**: `remove_matrix` cleans up and de-allocates a matrix.
3. **Comparison**: `eq_matrix` determines the equality of two matrices.
4. **Addition & Subtraction**: `sum_matrix` and `sub_matrix` handle matrix arithmetic.
5. **Scalar & Matrix Multiplication**: `mult_number` scales a matrix, while `mult_matrix` manages matrix-to-matrix multiplication.
6. **Transpose**: `transpose` returns the transpose of a matrix.
7. **Algebraic Complements**: `calc_complements` computes the matrix of algebraic complements.
8. **Determinant**: `determinant` evaluates the determinant of a matrix.
9. **Matrix Inversion**: `inverse_matrix` finds the inverse of a matrix.

Every function, except for `eq_matrix`, returns specific codes indicating successful operation or a particular error type.

### Development Guidelines

- **Language & Compiler**: The library adheres to the C11 standard and is compiled using `gcc`.
- **Code Location**: The source code resides in the `src` folder on the `develop` branch.
- **Coding Standards**: Legacy constructs were avoided, ensuring compliance with the POSIX.1-2017 standard. The Google style was followed throughout development.
- **Library Type**: The matrix library is static, complemented by the `matrix.h` header file.
- **Function Naming**: Each function is prefixed to maintain naming clarity.
- **Unit Testing**: Comprehensive unit-tests were designed using the Check library, targeting at least 80% coverage per function. `gcov` was employed to monitor this metric.
- **Compilation & Testing**: A Makefile, complete with targets (`all`, `clean`, `test`, `matrix.a`, `gcov_report`), facilitates building and testing operations. Specifically, `gcov_report` generates an HTML-based coverage report.
- **Precision**: The library guarantees accuracy up to six decimal places for fractional components.

This endeavor successfully distilled the essence of matrix operations, fortified by rigorous development standards, into a robust C library.