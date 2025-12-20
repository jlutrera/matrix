/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:50:15 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 14:43:51 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <iomanip>
#include "colors.hpp"

//
// CONSTRUCTOR
//
template<typename K>
Matrix<K>::Matrix(std::initializer_list<std::initializer_list<K>> init)
{
    rows = init.size();
    cols = init.begin()->size();
    data.reserve(rows * cols);

    for (const auto& row : init)
        for (const auto& val : row)
            data.push_back(val);
}

//
// GETTERS
//
template<typename K>
std::size_t Matrix<K>::nrows() const { return rows; }

template<typename K>
std::size_t Matrix<K>::ncols() const { return cols; }

template<typename K>
void Matrix<K>::add(const Matrix<K>& m)
{
    for (std::size_t i = 0; i < data.size(); ++i)
        data[i] += m.data[i];
}

template<typename K>
void Matrix<K>::sub(const Matrix<K>& m)
{
    for (std::size_t i = 0; i < data.size(); ++i)
        data[i] -= m.data[i];
}

template<typename K>
void Matrix<K>::scl(K a)
{
    for (auto& x : data)
        x *= a;
}

template<typename K>
K& Matrix<K>::operator()(std::size_t r, std::size_t c)
{
    return data[r * cols + c];
}

template<typename K>
const K& Matrix<K>::operator()(std::size_t r, std::size_t c) const
{
    return data[r * cols + c];
}

template<typename K>
std::pair<std::size_t, std::size_t> Matrix<K>::shape() const
{
    return {rows, cols};
}

template<typename K>
bool Matrix<K>::is_square() const
{
    return rows == cols;
}

template<typename K>
Vector<K> Matrix<K>::reshape_to_vector() const
{
    Vector<K> v;
    v.data = data;
    return v;
}


template<typename K>
void Matrix<K>::print(const std::string& text) const
{
    std::cout << text << "\n";

    auto [rows, cols] = shape();

    std::vector<size_t> colWidths(cols, 0);

    // ---- COMPUTE COLUMNS WIDTHS ----
    for (size_t c = 0; c < cols; ++c)
    {
        for (size_t r = 0; r < rows; ++r)
        {
            std::ostringstream ss;
            ss << (*this)(r, c);
            colWidths[c] = std::max(colWidths[c], ss.str().length());
        }
    }

    // ---------- TOP BORDER ----------
    std::cout << COLOR_BRACE "  \u250C " COLOR_RESET;
    for (size_t c = 0; c < cols; ++c)
    {
        std::cout << std::string(colWidths[c], ' ');
        if (c < cols - 1)
            std::cout << " ";
    }
    std::cout << COLOR_BRACE " \u2510\n" COLOR_RESET;

    // ---------- MATRIX CONTENT ----------
    for (size_t r = 0; r < rows; ++r)
    {
       std::cout << COLOR_BRACE "  \u2502 " COLOR_RESET;

        for (size_t c = 0; c < cols; ++c)
        {
            std::ostringstream ss;
            ss << std::setw(colWidths[c]) << (*this)(r, c);
            std::cout << COLOR_NUM << ss.str() << COLOR_RESET;
            if (c < cols - 1)
                std::cout << " ";
        }

        std::cout << COLOR_BRACE " \u2502\n" COLOR_RESET;
    }

    // ---------- BOTTOM BORDER ----------
    std::cout << COLOR_BRACE "  \u2514 " COLOR_RESET;
    for (size_t c = 0; c < cols; ++c)
    {
        std::cout << std::string(colWidths[c], ' ');
        if (c < cols - 1)
            std::cout << " ";
    }
    std::cout << COLOR_BRACE " \u2518\n" COLOR_RESET;
}
