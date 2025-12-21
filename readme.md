# Matrix Library — Mathematical Foundations

This project implements a small linear algebra library in **C++**, focusing on core operations used in:

- Scientific computing  
- Computer graphics  
- Numerical methods  
- Machine learning  

This document explains the **mathematical foundations** behind each implemented function.

---

## 1. Row Echelon Form (REF)

### Definition

A matrix is in **Row Echelon Form (REF)** if it satisfies:

1. All non-zero rows appear above any rows consisting entirely of zeros.
2. The leading coefficient (pivot) of each row is strictly to the right of the pivot in the row above.
3. All entries below each pivot are zero.

### Purpose

Row echelon form is used to:

- Solve systems of linear equations
- Compute the rank of a matrix
- Determine whether a matrix is invertible
- Prepare matrices for determinant or inverse computation

### Algorithm (Gaussian Elimination)

Given a matrix \( A \in \mathbb{R}^{m \times n} \):

1. For each column, find a non-zero pivot.
2. Swap rows if necessary to move the pivot into position.
3. Normalize the pivot row so the pivot becomes \(1\).
4. Eliminate all entries below the pivot.

The resulting matrix is upper triangular and **row-equivalent** to the original matrix.

---

## 2. Determinant

### Definition

The **determinant** of a square matrix \( A \in \mathbb{R}^{n \times n} \), denoted by  
\[
\det(A),
\]
is a scalar that represents:

- The scaling factor of the linear transformation defined by \(A\)
- Whether \(A\) is invertible
- The signed volume of the parallelepiped formed by its rows (or columns)

### Key Properties

- \( \det(A) = 0 \iff A \) is singular (not invertible)
- \( \det(AB) = \det(A)\det(B) \)
- Swapping two rows changes the sign of the determinant
- Multiplying a row by a scalar multiplies the determinant by that scalar

### Computation Methods

1. **Cofactor Expansion (Laplace Expansion)**  
   Suitable for small matrices and educational clarity.

2. **Triangularization (Gaussian Elimination)**  
   Efficient for large matrices.

This project uses **cofactor expansion** for clarity and mathematical transparency.

---

## 3. Matrix Inverse

### Definition

A square matrix \( A \in \mathbb{R}^{n \times n} \) is **invertible** if there exists a matrix  
\( A^{-1} \) such that:

\[
A A^{-1} = A^{-1} A = I_n
\]

where \( I_n \) is the identity matrix.

### Existence of the Inverse

A matrix is invertible if and only if:

- \( \det(A) \neq 0 \)
- Its rows (or columns) are linearly independent

### Algorithm (Gauss–Jordan Elimination)

The inverse is computed using the augmented matrix:

\[
[A \mid I]
\]

Steps:

1. Construct the augmented matrix \( [A \mid I] \).
2. Apply row operations to transform \(A\) into \(I\).
3. The right block becomes \( A^{-1} \).

If a pivot cannot be found at any step, the matrix is singular and has no inverse.

---

## 4. Matrix–Matrix Multiplication

### Definition

Given matrices  
\( A \in \mathbb{R}^{m \times n} \) and  
\( B \in \mathbb{R}^{n \times p} \),  
their product \( C = AB \in \mathbb{R}^{m \times p} \) is defined by:

\[
C_{ij} = \sum_{k=0}^{n-1} A_{ik} B_{kj}
\]

### Interpretation

Matrix multiplication represents:

- Composition of linear transformations
- Sequential application of transformations
- Change of coordinate systems

### Properties

- **Not commutative:** \( AB \neq BA \)
- **Associative:** \( (AB)C = A(BC) \)
- **Distributive:** \( A(B + C) = AB + AC \)

---

## 5. Matrix–Vector Multiplication

### Definition

Given a matrix  
\( A \in \mathbb{R}^{m \times n} \)  
and a vector  
\( v \in \mathbb{R}^{n} \),  
the product \( u = Av \in \mathbb{R}^{m} \) is defined as:

\[
u_i = \sum_{k=0}^{n-1} A_{ik} v_k
\]

### Interpretation

Matrix–vector multiplication applies a **linear transformation** to a vector.  
This operation is fundamental in:

- Computer graphics (rotations, scaling, projections)
- Machine learning (linear layers)
- Physics simulations
- Solving systems of linear equations

---

## 6. Dot Product

### Definition

Given two vectors  
\( a, b \in \mathbb{R}^{n} \),  
their **dot product** is defined as:

\[
a \cdot b = \sum_{i=0}^{n-1} a_i b_i
\]

### Geometric Meaning

The dot product measures:

- Similarity between vectors
- Projection of one vector onto another
- The cosine of the angle between them:

\[
a \cdot b = \|a\| \|b\| \cos(\theta)
\]

### Applications

- Checking orthogonality: \( a \cdot b = 0 \)
- Computing vector lengths and angles
- Machine learning (cosine similarity)
- Physics (work: \( W = \vec{F} \cdot \vec{d} \))

---

## 7. Printing and Representation

Although not a mathematical operation, matrix printing is essential for:

- Debugging
- Visual verification of transformations
- Understanding intermediate steps in algorithms

The printed matrix reflects the internal **row-major storage** while preserving its mathematical structure.

---

## Summary Table

| Function      | Mathematical Concept     | Purpose                                   |
|---------------|--------------------------|-------------------------------------------|
| `row_echelon` | Gaussian elimination     | Solve systems, rank, invertibility        |
| `determinant`| Determinant              | Volume, invertibility, orientation        |
| `inverse`    | Gauss–Jordan elimination | Compute \( A^{-1} \)                      |
| `mul_mat`    | Matrix multiplication    | Compose linear transformations            |
| `mul_vec`    | Matrix–vector product    | Apply a linear transformation             |
| `dot`        | Inner product            | Angle, projection, similarity             |
| `print`      | Representation           | Debugging and verification                |

---

## Final Notes

This project introduces the essential building blocks of **linear algebra**.  
A solid understanding of the mathematics behind each operation is crucial for writing:

- Correct code  
- Efficient algorithms  
- Numerically stable implementations
