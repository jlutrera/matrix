/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:44 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 11:34:44 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

template<typename K>
    class Matrix;
template<typename K>
class Vector
{
    public:
        Vector() = default;
        Vector(std::initializer_list<K> init);

        std::size_t size() const;

        void print(const std::string& text) const;
        void add(const Vector<K>& v);
        void sub(const Vector<K>& v);  
        void scl(K a);
        Matrix<K> reshape_to_matrix(std::size_t r, std::size_t c) const;

        const K& operator[](std::size_t i) const;
        K& operator[](std::size_t i);

    private:
        std::vector<K> data;
};

#include "../tpp/vector.tpp"

