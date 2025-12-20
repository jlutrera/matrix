/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:51:09 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 23:53:25 by jutrera-         ###   ########.fr       */
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

// ---------- Linear Interpolation ----------
template<typename K>
Vector<K> lerp(const Vector<K>& u, const Vector<K>& v, double t);

template<typename K>
Matrix<K> lerp(const Matrix<K>& A, const Matrix<K>& B, double t);

// ---------- Dot Product ----------
template<typename K>
K dot(const Vector<K>& u, const Vector<K>& v);

// ---------- Norms ----------
template<typename K>
double norm_1(const Vector<K>& u);

template<typename K>
double norm(const Vector<K>& u);

template<typename K>
double norm_inf(const Vector<K>& u);

// ---------- Cosine ----------
template<typename K>
double angle_cos(const Vector<K>& u, const Vector<K>& v);

// ---------- Cross Product ----------
template<typename K>
Vector<K> cross_product(const Vector<K>& u, const Vector<K>& v);

// ---------- Matrix Multiplication ----------
template<typename K>
Matrix<K> mul_mat(const Matrix<K>& B);

// ---------- Linear Map -----------------
template<typename K>
Vector<K> mul_vec(const Vector<K>& v);

// ---------- Trace ----------------------
template<typename K>
K trace(const Matrix<K>& A);

// ---------- Transpose ------------------
template<typename K>
Matrix<K> transpose(const Matrix<K>& A);

#include "../tpp/utilities.tpp"
