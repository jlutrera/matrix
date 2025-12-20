/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:51:09 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 22:51:10 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"
#include "matrix.hpp"
#include <utility>   // std::pair
#include <cmath>     // std::sqrt, std::abs

// ---------- Linear Combination ----------
template<typename K>
Vector<K> linear_combination(K a, const Vector<K>& u,
                             K b, const Vector<K>& v);

// ---------- Dot Product ----------
template<typename K>
K dot(const Vector<K>& u, const Vector<K>& v);

// ---------- Norms ----------
template<typename K>
K norm_1(const Vector<K>& u);

template<typename K>
K norm_2(const Vector<K>& u);

template<typename K>
K norm_inf(const Vector<K>& u);

// ---------- Angle Between Vectors ----------
template<typename K>
double angle(const Vector<K>& u, const Vector<K>& v);

// ---------- Cosine Similarity ----------
template<typename K>
double cosine_similarity(const Vector<K>& u, const Vector<K>& v);

#include "../tpp/utilities.tpp"
