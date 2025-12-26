/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:18:17 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/26 12:57:19 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <complex>
#include <stdexcept>
#include <algorithm>
#include "traits.hpp"

// FUSED MUL-ADD (REAL: FMA, COMPLEX/OTHER: a*b + c)
template<typename K>
K fused_mul_add(K a, K b, K c)
{
    if constexpr (is_complex_v<K>)
        return a * b + c;   // complejos: no hay fma disponible
    else
        return std::fma(a, b, c);   // más preciso para reales
}

// ABS VALUE (REAL: manual, COMPLEX: std::abs)
template<typename K>
double abs_value(const K& x)
{
    if constexpr (is_complex_v<K>)
        return std::abs(x);        // complejos: std::abs
    else
        return (x < 0 ? -static_cast<double>(x) : static_cast<double>(x));
}

//  LINEAR COMBINATION
template<typename K>
Vector<K> linear_combination(K a, const Vector<K>& u,
                             K b, const Vector<K>& v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    Vector<K> result = u;

    for (std::size_t i = 0; i < u.size(); ++i)
        result[i] = fused_mul_add(a, u[i], b * v[i]);

    return result;
}

// LINEAR INTERPOLATION (VECTORS)
template<typename K>
Vector<K> lerp(const Vector<K>& u, const Vector<K>& v, double t)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    K a = static_cast<K>(1.0 - t);
    K b = static_cast<K>(t);

    Vector<K> result = u;

    for (std::size_t i = 0; i < u.size(); ++i)
        result[i] = fused_mul_add(a, u[i], b * v[i]);

    return result;
}

// LINEAR INTERPOLATION (MATRICES)
template<typename K>
Matrix<K> lerp(const Matrix<K>& A, const Matrix<K>& B, double t)
{
    if (A.nrows() != B.nrows() || A.ncols() != B.ncols())
        throw std::invalid_argument("Matrices must have the same dimensions");

    K a = static_cast<K>(1.0 - t);
    K b = static_cast<K>(t);

    Matrix<K> result = A;

    for (std::size_t r = 0; r < A.nrows(); ++r)
        for (std::size_t c = 0; c < A.ncols(); ++c)
            result(r, c) = fused_mul_add(a, A(r, c), b * B(r, c));

    return result;
}

//  DOT PRODUCT
template<typename K>
K dot(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    K sum = K(0);

    for (std::size_t i = 0; i < u.size(); ++i)
    {
        if constexpr (is_complex_v<K>)
            sum += std::conj(u[i]) * v[i];
        else
            sum += u[i] * v[i];
    }

    return sum;
}

//  NORM 1
template<typename K>
double norm_1(const Vector<K>& u)
{
    double sum = 0.0;

    for (std::size_t i = 0; i < u.size(); ++i)
        sum += abs_value(u[i]);

    return sum;
}

// L2 NORM
template<typename K>
double norm(const Vector<K>& u)
{
    double sum = 0.0;

    for (std::size_t i = 0; i < u.size(); ++i)
    {
        if constexpr (is_complex_v<K>)
            sum += std::norm(u[i]);
        else
            sum = std::fma((double)u[i], (double)u[i], sum);            
    }

    return std::pow(sum, 0.5);
}

// INFINITY NORM
template<typename K>
double norm_inf(const Vector<K>& u)
{
    double maxv = 0.0;

    for (std::size_t i = 0; i < u.size(); ++i)
        maxv = std::max(maxv, abs_value(u[i]));

    return maxv;
}

//  COSINE OF ANGLE
template<typename K>
double angle_cos(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != v.size())
        throw std::invalid_argument("Vectors must have the same size");

    double denom = norm(u) * norm(v);
    if (denom == 0)
        throw std::invalid_argument("Angle undefined for zero vector");

    auto d = dot(u, v);
    double numerator;

    if constexpr (is_complex_v<K>)
        numerator = abs_value(d);// Caso COMPLEJO → usar |<u,v>|
    else
        numerator = static_cast<double>(d);// Caso REAL → usar <u,v> con signo

    return numerator / denom;
}

//  CROSS PRODUCT (3D)
template<typename K>
Vector<K> cross_product(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::invalid_argument("Cross product is defined for 3D vectors only");

    Vector<K> result({K(0), K(0), K(0)});

    result[0] = fused_mul_add(u[1], v[2], -(u[2] * v[1]));
    result[1] = fused_mul_add(u[2], v[0], -(u[0] * v[2]));
    result[2] = fused_mul_add(u[0], v[1], -(u[1] * v[0]));

    return result;
}
