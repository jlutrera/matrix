/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:50:42 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 22:50:43 by jutrera-         ###   ########.fr       */
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
K norm_1(const Vector<K>& u)
{
    K sum = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        sum += std::abs(u[i]);
    return sum;
}

// ---------- L2 norm ----------
template<typename K>
K norm_2(const Vector<K>& u)
{
    K sum = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        sum += u[i] * u[i];
    return std::sqrt(sum);
}

// ---------- Infinity norm ----------
template<typename K>
K norm_inf(const Vector<K>& u)
{
    K maxv = 0;
    for (std::size_t i = 0; i < u.size(); ++i)
        maxv = std::max(maxv, std::abs(u[i]));
    return maxv;
}



// ======================================================
//  ANGLE BETWEEN VECTORS
// ======================================================
template<typename K>
double angle(const Vector<K>& u, const Vector<K>& v)
{
    double d = dot(u, v);
    double n = norm_2(u) * norm_2(v);

    if (n == 0)
        throw std::invalid_argument("Angle undefined for zero vector");

    return std::acos(d / n);
}



// ======================================================
//  COSINE SIMILARITY
// ======================================================
template<typename K>
double cosine_similarity(const Vector<K>& u, const Vector<K>& v)
{
    double n = norm_2(u) * norm_2(v);

    if (n == 0)
        throw std::invalid_argument("Cosine similarity undefined for zero vector");

    return dot(u, v) / n;
}
