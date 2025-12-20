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
#include <iostream>

template<typename K>
    class Vector;
template<typename K>
class Matrix
{
    public:
        Matrix() = default;
        Matrix(std::initializer_list<std::initializer_list<K>> init);

        std::size_t nrows() const;
        std::size_t ncols() const;
        std::pair<std::size_t, std::size_t> shape() const;
        void print(const std::string& text) const;
        bool is_square() const;
        void add(const Matrix<K>& m);
        void sub(const Matrix<K>& m);
        void scl(K a);
        Vector<K> reshape_to_vector() const;
        const K& operator()(std::size_t r, std::size_t c) const;
        K& operator()(std::size_t r, std::size_t c);

    private:
        Matrix(std::size_t r, std::size_t c, const std::vector<K>& values) : rows(r), 
                                                                             cols(c),
                                                                             data(values) {}
        std::size_t rows = 0;
        std::size_t cols = 0;
        std::vector<K> data;
};

#include "../tpp/matrix.tpp"

