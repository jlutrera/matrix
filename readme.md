# Matrix Library — Mathematical Foundations

This project implements a small linear algebra library in **C++**, focused on core operations used in scientific computing, computer graphics, numerical methods, and machine learning.

All mathematical expressions are written using **LaTeX notation**, ensuring correct rendering on platforms such as **GitHub** and compatibility with standard mathematical conventions.

---

## 1. Row Echelon Form (REF)

### Definition

A matrix $A$ is in **Row Echelon Form (REF)** if it satisfies:

1. All non-zero rows appear above any rows of all zeros.
2. The leading coefficient (pivot) of each non-zero row is strictly to the right of the pivot of the row above it.
3. All entries below each pivot are zero.

### Purpose

Row echelon form is used to:

- Solve linear systems
- Compute the rank of a matrix
- Determine invertibility
- Prepare matrices for determinant or inverse computation

### Algorithm (Gaussian Elimination)

Given a matrix $A \in \mathbb{R}^{m \times n}$:

1. For each column $j$, find a pivot element $a_{ij} \neq 0$.
2. Swap rows to move the pivot into position.
3. Normalize the pivot row so that the pivot equals $1$.
4. Eliminate all entries below the pivot.

The resulting matrix is upper triangular and **row-equivalent** to $A$.

---

## 2. Determinant

### Definition

For a square matrix $A \in \mathbb{R}^{n \times n}$, the **determinant** $\det(A)$ is a scalar that represents:

- The scaling factor of the linear transformation induced by $A$
- Whether $A$ is invertible
- The signed volume of the parallelepiped spanned by its rows or columns

### Fundamental Properties

- $\det(A) = 0 \iff A$ is singular
- $\det(AB) = \det(A)\,·\det(B)$
- Swapping two rows changes the sign of the determinant
- Multiplying a row by $\lambda$ multiplies the determinant by $\lambda$

### Computation

Two classical methods exist:

1. **Cofactor Expansion (Laplace Expansion)**  
   Suitable for small matrices and educational purposes.

2. **Triangularization (Gaussian Elimination)**  
   Efficient for large matrices.

This project uses **cofactor expansion** for mathematical clarity.

---

## 3. Matrix Inverse

### Definition

A square matrix $A$ is **invertible** if there exists a matrix $A^{-1}$ such that:

$$
A·A^{-1} = I \quad \text{and} \quad A^{-1}·A = I
$$

where $I$ is the identity matrix.

### Existence Conditions

A matrix $A$ is invertible if and only if:

- $\det(A) \neq 0$
- Its rows (or columns) are linearly independent

### Algorithm (Gauss–Jordan Elimination)

The inverse is computed using the augmented matrix:

$$
[A \mid I]
$$

Steps:

1. Apply row operations to transform $A$ into $I$.
2. Apply the same operations to $I$.
3. The resulting right block is $A^{-1}$.

If a pivot cannot be found at any step, $A$ is singular and has no inverse.

---

## 4. Matrix–Matrix Multiplication

### Definition

Given matrices $A \in \mathbb{R}^{m \times n}$ and $B \in \mathbb{R}^{n \times p}$, their product $C = AB$ is defined by:

$$
C_{ij} = \sum_{k=0}^{n-1} A_{ik}·B_{kj}
$$

The resulting matrix $C$ belongs to $\mathbb{R}^{m \times p}$.

### Interpretation

Matrix multiplication represents:

- Composition of linear transformations
- Sequential application of transformations
- Change of coordinate systems

### Properties

- Non-commutative: $A·B \neq B·A$
- Associative: $(A·B)·C = A·(B·C)$
- Distributive: $A·(B+C) = A·B+A·C$

---

## 5. Matrix–Vector Multiplication

### Definition

Given $A \in \mathbb{R}^{m \times n}$ and $v \in \mathbb{R}^n$, the product $Av \in \mathbb{R}^m$ is defined by:

$$
(Av)_i = \sum_{k=0}^{n-1} A_{ik}·v_k
$$

### Interpretation

Matrix–vector multiplication applies a linear transformation to a vector. It is fundamental in:

- Computer graphics (rotations, scaling, projections)
- Machine learning (linear layers)
- Physics simulations
- Solving linear systems

---

## 6. Dot Product

### Definition

For vectors $a, b \in \mathbb{R}^n$, the **dot product** is defined as:

$$
a \cdot b = \sum_{i=0}^{n-1} a_i · b_i
$$

### Geometric Interpretation

The dot product satisfies:

$$
a \cdot b = \lVert a \rVert \,· \lVert b \rVert \,· \cos(\theta)
$$

where $\theta$ is the angle between $a$ and $b$.

### Applications

- Orthogonality testing ($a \cdot b = 0$)
- Computing vector norms and angles
- Cosine similarity in machine learning
- Physical work: $W = F \cdot d$

---

## 7. Printing and Representation

Although not a mathematical operation, matrix printing is essential for:

- Debugging numerical algorithms
- Verifying intermediate results
- Visualizing matrix transformations

The printed representation preserves row-major order and reflects the underlying mathematical structure.

---

## Summary Table

| Function       | Mathematical Concept        | Purpose                                   |
|----------------|-----------------------------|-------------------------------------------|
| `row_echelon`  | Gaussian elimination        | Solve systems, rank computation            |
| `determinant`  | Determinant                 | Volume, invertibility, orientation         |
| `inverse`      | Gauss–Jordan elimination    | Compute $A^{-1}$                           |
| `mul_mat`      | Matrix multiplication       | Compose linear transformations             |
| `mul_vec`      | Matrix–vector multiplication| Apply linear transformations               |
| `dot`          | Inner product               | Angle, projection, similarity              |
| `print`        | Representation              | Debugging and verification                 |

---

## Final Notes

This project introduces the fundamental building blocks of linear algebra.
A solid understanding of the mathematics behind each operation is essential for writing **correct**, **efficient**, and **numerically stable** implementations.
