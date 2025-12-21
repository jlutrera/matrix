/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:06:18 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/21 14:31:22 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "matrix.hpp"
#include "algebra.hpp"
#include "colors.hpp"
#include <iostream>

void ex07()
{
    using K = float;

    std::cout << COLOR_EX "[Exercise 07] LINEAR MAP, MATRIX MULTIPLICATION\n" COLOR_RESET;
    
    Vector<K> u({1, 2, 3});
    Vector<K> v({4, -5, 6});
    Matrix<K> A({{1, 2, 3}, {4, 5, 6}});
    Matrix<K> B({{7, 8, 9}, {10, 11, 12}});

    std::cout << COLOR_NAME "I. Data\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");
    A.print("  A");
    B.print("  B");

    std::cout << COLOR_NAME "II. Results\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    try
    {
        Matrix<K> C = A.mul_mat(B);
        C.print("  A * B");
    }
    catch(const std::exception& e)
    {
        std::cout << COLOR_ERR "  Error: " << e.what() << COLOR_RESET "\n";
    }
    
    try
    {
        Vector<K> mapped = A.mul_vec(u);
        mapped.print("  A * u");
    }
    catch(const std::exception& e)
    {
        std::cout << COLOR_ERR "  Error: " << e.what() << COLOR_RESET "\n";
    }
}
