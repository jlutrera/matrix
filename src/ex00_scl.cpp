/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00_scl.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:43:40 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/22 12:27:22 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "matrix.hpp"
#include "colors.hpp"
#include <iostream>

void ex00_scl()
{
    using K = float;

    std::cout << COLOR_EX "[Exercise 00] SCALING\n" COLOR_RESET;

    Vector<K> u({1, 12, 3});
    Vector<K> v({4, 5, -6});
    Matrix<K> A({{1, -2}, {3, 4}});
    Matrix<K> B({{5, 6}, {17, 8}});
    Vector<K> temp;
    Matrix<K> tempM;

    std::cout << COLOR_NAME "I. Data\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");
    A.print("  A");
    B.print("  B");

    std::cout << COLOR_NAME "IV. Result\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    temp = u;
    temp.scl(2);
    temp.print("  2 * u");
    tempM = A;
    tempM.scl(3);
    tempM.print("  3 * A");
}
