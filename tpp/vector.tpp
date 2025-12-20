/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:50:23 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 22:24:45 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <iomanip>
#include "colors.hpp"

template<typename K>
Vector<K>::Vector(std::initializer_list<K> init) : data(init) {}

template<typename K>
std::size_t Vector<K>::size() const
{
    return data.size();
}

template<typename K>
void Vector<K>::add(const Vector<K>& u)
{
    for (std::size_t i = 0; i < data.size(); ++i)
        data[i] += u.data[i];
}

template<typename K>
void Vector<K>::sub(const Vector<K>& u)
{
    for (std::size_t i = 0; i < data.size(); ++i)
        data[i] -= u.data[i];
}

template<typename K>
void Vector<K>::scl(K a)
{
    for (auto& x : data)
        x *= a;
}

template<typename K>
const K& Vector<K>::operator[](std::size_t i) const
{
    return data[i];
}

template<typename K>
K& Vector<K>::operator[](std::size_t i)
{
    return data[i];
}

template<typename K>
void Vector<K>::print(const std::string& text) const
{
    std::cout << text << "\n";
    std::cout << COLOR_BRACE "  [ " COLOR_RESET;
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        std::cout << COLOR_NUM << data[i] << COLOR_RESET;
        if (i < data.size() - 1)
            std::cout << ", ";
    }
    std::cout << COLOR_BRACE " ]\n\n" COLOR_RESET;
}

template<typename K>
Matrix<K> Vector<K>::reshape_to_matrix(std::size_t r, std::size_t c) const
{
    if (data.size() != r * c)
        throw std::invalid_argument("Vector size does not match matrix shape");

    return Matrix<K>(r, c, data);
}
