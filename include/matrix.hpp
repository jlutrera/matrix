/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:29 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 11:34:29 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <initializer_list>
#include <string>
#include <cstddef>
#include <utility> // std::pair
#include <stdexcept> // invalid_argument

template<typename K>
    class Vector;
template<typename K>
class Matrix
{
    public:
        Matrix() = default;
        Matrix(std::initializer_list<std::initializer_list<K>> init);
        Matrix(std::size_t r, std::size_t c, const std::vector<K>& values);

        std::size_t nrows() const;
        std::size_t ncols() const;
        std::pair<std::size_t, std::size_t> shape() const;

        void print(const std::string& text) const;
        bool is_square() const;

        void add(const Matrix<K>& m);
        void sub(const Matrix<K>& m);
        void scl(K a);

        Vector<K> reshape_to_vector() const;

        Matrix<K> mul_mat(const Matrix<K>& B);
        Vector<K> mul_vec(const Vector<K>& v);

        K trace();
        Matrix<K> transpose();
        Matrix<K> row_echelon() const;
        K determinant();
        Matrix<K> inverse();
        std::size_t rank() const;

        static Matrix<K> projectionOpenGL(K fov, K ratio, K near, K far);
        static Matrix<K> projectionDirectX(K fov, K ratio, K near, K far);

        const K& operator()(std::size_t r, std::size_t c) const;
        K& operator()(std::size_t r, std::size_t c);

    private:
        std::size_t rows = 0;
        std::size_t cols = 0;
        std::vector<K> data;
};

#include "../tpp/matrix.tpp"

