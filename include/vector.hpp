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

#include <vector> //std::vector<K> data forma parte de la interfaz
#include <initializer_list> //uso std::initializer_list<K> en el constructor
#include <string> //print() recibe un std::string 
#include <cstddef> //para std::size_t

template<typename K>
    class Matrix;
template<typename K>
class Vector
{
    public:
        Vector() = default;
        Vector(std::initializer_list<K> init);

        std::size_t size() const;
        void resize(std::size_t n, K value = K());

        void print(const std::string& text) const;

        void add(const Vector<K>& v);
        void sub(const Vector<K>& v);  
        void scl(K a);

        Matrix<K> reshape_to_matrix(std::size_t r, std::size_t c) const;

        const K& operator[](std::size_t i) const;
        K& operator[](std::size_t i);

    private:
        std::vector<K> data;

        template<typename T>
        friend class Matrix; // para permitir reshape_to_vector en Matrix
};

#include "../tpp/vector.tpp"

