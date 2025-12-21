# Matrix Library — Mathematical Foundations

This project implements a small linear algebra library in C++, focusing on the core operations used in scientific computing, computer graphics, numerical methods, and machine learning.  
This document explains the mathematical basis behind each implemented function, following the structure and requirements of the project subject.

---

# 1. Row Echelon Form (REF)

## Definition
A matrix is in Row Echelon Form if:

- All non-zero rows appear above any rows of all zeros.
- Each row's leading coefficient (pivot) is to the right of the pivot in the row above.
- All entries below each pivot are zero.

## Purpose
Row echelon form is used to:

- Solve linear systems
- Compute the rank of a matrix
- Determine whether a matrix is invertible
- Prepare matrices for determinant or inverse computation

## Algorithm (Gaussian elimination)
1. For each column, find a pivot (a non-zero entry).
2. Swap rows if needed to bring the pivot into position.
3. Normalize the pivot row so the pivot becomes 1.
4. Eliminate all entries below the pivot.

This produces an upper triangular matrix while preserving row equivalence.

---

# 2. Determinant

## Definition
The determinant of a square matrix A, written as det(A), is a scalar that measures:

- The scaling factor of the linear transformation represented by A
- Whether A is invertible
- The signed volume of the parallelepiped formed by its rows or columns

## Key properties
- det(A) = 0  <=>  A is singular (not invertible)
- det(AB) = det(A) * det(B)
- Swapping two rows changes the sign of the determinant
- Multiplying a row by a scalar multiplies the determinant by that scalar

## Computation
Two classical methods:

1. **Cofactor expansion (Laplace expansion)**  
   Used for small matrices or educational purposes.

2. **Triangularization (Gaussian elimination)**  
   Efficient for large matrices.

This project uses cofactor expansion for clarity and mathematical transparency.

---

# 3. Matrix Inverse

## Definition
A square matrix A is invertible if there exists a matrix A_inverse such that:

- A * A_inverse = I  
- A_inverse * A = I  

where I is the identity matrix.

## When does the inverse exist?
A matrix is invertible if:

- det(A) != 0
- Its rows (or columns) are linearly independent

## Algorithm (Gauss–Jordan elimination)
The inverse is computed using the augmented matrix [A | I]:

1. Form the augmented matrix [A | I].
2. Apply row operations to transform A into the identity matrix.
3. The right side becomes A_inverse.

If no pivot can be found during the process, the matrix is singular and has no inverse.

---

# 4. Matrix–Matrix Multiplication

## Definition
Given matrices A (size m x n) and B (size n x p), their product C = A * B is an m x p matrix defined by:

C[i, j] = sum over k = 0..n-1 of A[i, k] * B[k, j]

## Interpretation
Matrix multiplication represents:

- Composition of linear transformations
- Applying multiple transformations in sequence
- Changing coordinate systems

## Properties
- Not commutative: A * B != B * A
- Associative: (A * B) * C = A * (B * C)
- Distributive: A * (B + C) = A * B + A * C

---

# 5. Matrix–Vector Multiplication

## Definition
Given a matrix A (size m x n) and a vector v (size n):

(A * v)[i] = sum over k = 0..n-1 of A[i, k] * v[k]

## Interpretation
Matrix–vector multiplication applies a linear transformation to a vector.  
This is fundamental in:

- Computer graphics (rotations, scaling, projections)
- Machine learning (linear layers)
- Physics simulations
- Solving systems of equations

---

# 6. Dot Product

## Definition
For two vectors a and b of size n:

a · b = sum over i = 0..n-1 of a[i] * b[i]

## Geometric meaning
The dot product measures:

- Similarity between two vectors
- Projection of one vector onto another
- The cosine of the angle between them:

a · b = |a| * |b| * cos(theta)

## Applications
- Checking orthogonality (a · b = 0)
- Computing vector lengths and angles
- Machine learning (cosine similarity)
- Physics (work = force * displacement)

---

# 7. Printing and Representation

Although not a mathematical operation, the print function is essential for:

- Debugging
- Visual verification of matrix transformations
- Understanding intermediate steps in algorithms

The printed matrix reflects the internal row-major storage and preserves the mathematical structure.

---

# Summary Table

| Function      | Mathematical concept     | Purpose                                      |
|---------------|--------------------------|----------------------------------------------|
| row_echelon   | Gaussian elimination     | Solve systems, rank, invertibility           |
| determinant   | Determinant              | Volume, invertibility, orientation           |
| inverse       | Gauss–Jordan elimination | Compute A_inverse                            |
| mul_mat       | Matrix multiplication    | Compose linear transformations               |
| mul_vec       | Matrix–vector product    | Apply a linear transformation                |
| dot           | Inner product            | Angle, projection, similarity                |
| print         | Representation           | Debugging and verification                   |

---

# Final Notes

This project introduces the essential building blocks of linear algebra.  
Understanding the mathematics behind each operation is crucial for writing correct, efficient, and numerically stable code.
