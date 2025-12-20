/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:50:42 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 23:57:58 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// ======================================================
//  LINEAR COMBINATION
// ======================================================
template<typename K>
Vector<K> linear_combination(K a, const Vector<K>& u,
                             K b, const Vector<K>& v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    Vector<K> result = u;
    result.scl(a);

    Vector<K> temp = v;
    temp.scl(b);

    result.add(temp);
    return result;
}

// ======================================================
// LINEAR INTERPOLATION
// ======================================================

// ---------- For vectors ----------
template<typename K>
Vector<K> lerp(const Vector<K>& u, const Vector<K>& v, double t)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    Vector<K> result = u;
    result.scl(static_cast<K>(1.0 - t));

    Vector<K> temp = v;
    temp.scl(static_cast<K>(t));

    result.add(temp);
    return result;
}

// ---------- For matrices ----------
template<typename K>
Matrix<K> lerp(const Matrix<K>& A, const Matrix<K>& B, double t)
{
    if (A.rows() != B.rows() || A.cols() != B.cols())
        throw std::invalid_argument("Matrices must have the same dimensions");
    Matrix<K> result = A;
    result.scl(static_cast<K>(1.0 - t));
    Matrix<K> temp = B;
    temp.scl(static_cast<K>(t));
    result.add(temp);
    return result;
}

// ======================================================
//  DOT PRODUCT
// ======================================================
template<typename K>
K dot(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    K sum = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        sum += u[i] * v[i];

    return sum;
}

// ======================================================
//  NORMS
// ======================================================

// ---------- L1 norm ----------
template<typename K>
double norm_1(const Vector<K>& u)
{
    double sum = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        sum += std::abs(u[i]);
    return sum;
}

// ---------- L2 norm ----------
template<typename K>
double norm(const Vector<K>& u)
{
    double sum = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        sum += u[i] * u[i];
    return std::sqrt(sum);
}

// ---------- Infinity norm ----------
template<typename K>
double norm_inf(const Vector<K>& u)
{
    double maxv = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        maxv = std::max(maxv, std::abs(u[i]));
    return maxv;
}



// ======================================================
//  COSINE BETWEEN VECTORS
// ======================================================
template<typename K>
double angle_cos(const Vector<K>& u, const Vector<K>& v)
{
    double d = dot(u, v);
    double n = norm(u) * norm(v);

    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    if (n == 0)
        throw std::invalid_argument("Angle undefined for zero vector");

    return d / n;
}

// ======================================================
//  CROSS PRODUCT
// ======================================================
template<typename K>
Vector<K> cross_product(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::invalid_argument("Cross product is defined for 3D vectors only");

    Vector<K> result({0, 0, 0});
    result[0] = u[1] * v[2] - u[2] * v[1];
    result[1] = u[2] * v[0] - u[0] * v[2];
    result[2] = u[0] * v[1] - u[1] * v[0];
    return result;
}

// ======================================================
//  MATRIX MULTIPLICATION
// ======================================================
template<typename K>
Matrix<K> mul_mat(const Matrix<K>& B)
{
    throw std::logic_error("Matrix multiplication not implemented yet");
}

// ======================================================
//  LINEAR MAP
// ======================================================
template<typename K>
Vector<K> mul_vec(const Vector<K>& v)
{
    throw std::logic_error("Linear map not implemented yet");
}

// ======================================================
//  TRACE OF A MATRIX
// ======================================================
template<typename K>
K trace(const Matrix<K>& A)
{
    if (!A.is_square())
        throw std::invalid_argument("Trace is defined for square matrices only");
    K sum = 0;
    for (std::size_t i = 0; i < A.nrows(); ++i)
        sum += A(i, i);
    return sum;
}

// ======================================================
//  TRANSPOSE OF A MATRIX
// ======================================================
template<typename K>
Matrix<K> transpose(const Matrix<K>& A)
{
    throw std::logic_error("Transpose not implemented yet");
}

