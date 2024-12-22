# 🫎 Linear Equation System Solver using Gauss-Jordan Elimination written in C++

## Table of Contents
1. [Introduction](#introduction)
2. [Solving Linear System](#solving-linear-equation-system)
    - [Term and Theories](#gauss-jordan-elimination)
    - [Gauss-Jordan Elimination Method](#gauss-jordan-elimination)
3. [Code Explanation](#code-explanation)
4. [Contributors](#contributors)

## Introduction
This repo is written as the final project of CAK2BAB2 (Analisis Kompleksitas Algoritma). You'll find implementations, visualizations, and notes about the algorithm 🧠.

## Solving Linear Equation System

### What is System of Linear Equations?
It's a collection of linear equations which involve the same set of variables.

$$
\begin{align*}
2x + y - z &= 8 \\
-3x - y + 2z &= -11 \\
-2x + y + 2z &= -3
\end{align*}
$$

This system can be represented in matrix form as augmented matrix:

$$
\begin{pmatrix}
2 & 1 & -1 & | & 8 \\
-3 & -1 & 2 & | & -11 \\
-2 & 1 & 2 & | & -3
\end{pmatrix}
$$

an augmented matrix for a system of equations is a matrix of numbers in which each row represents the equation and each column represents all the coefficients for a single variable.

The reduced row echelon form (RREF) of the matrix is:

$$
\begin{pmatrix}
1 & 0 & 0 & | & 2 \\
0 & 1 & 0 & | & 3 \\
0 & 0 & 1 & | & -1
\end{pmatrix}
$$

A matrix is said to be in reduced row echelon form when it is in row echelon form and its basic columns are vector of the standard basis.

When the coefficient matrix of a linear system is in reduced row echelon form, it is straightforward to derive the solution of the system from the coefficient matrix and the vector of constants.

1. **Forward Elimination**: Convert the matrix to an upper triangular form.
2. **Backward Elimination**: Convert the upper triangular matrix to a diagonal matrix.
3. **Normalization**: Scale the diagonal elements to 1 to achieve the RREF.

## Code Explanation
The code is structured to perform the following tasks:
- Read the input matrix.
- Apply the Gauss-Jordan elimination method.
- Output the solution to the system of equations.

```cpp
// Example code snippet
#include <iostream>
#include <vector>

void gaussJordan(std::vector<std::vector<double>>& matrix) {
     // Implementation of Gauss-Jordan elimination
}

int main() {
     // Example usage of the solver
     std::vector<std::vector<double>> matrix = {
          {2, 1, -1, 8},
          {-3, -1, 2, -11},
          {-2, 1, 2, -3}
     };
     gaussJordan(matrix);
     return 0;
}
```

## Usage
To use the linear system solver, compile the code and run the executable. Provide the matrix as input, and the program will output the solution.

## Contributors
- **Contributor 1**: [GitHub Profile](https://github.com/contributor1)
- **Contributor 2**: [GitHub Profile](https://github.com/contributor2)
- **Contributor 3**: [GitHub Profile](https://github.com/contributor3)
