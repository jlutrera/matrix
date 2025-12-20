/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:35:05 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 11:35:05 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "matrix.hpp"
#include "colors.hpp"
#include <iostream>

void ex00()
{
    using K = float;

    std::cout << "*****************************************\n";
    std::cout << "* " COLOR_EX  "[Exercise 00] Add, Subtract and Scale" COLOR_RESET " *\n";
    std::cout << "*****************************************\n";

    Vector<K> u({1, 12, 3});
    Vector<K> v({4, 5, -6});
    Matrix<K> A({{1, -2}, {3, 4}});
    Matrix<K> B({{5, 6}, {17, 8}});
    Vector<K> temp;
    Matrix<K> tempM;

    std::cout << COLOR_NAME "I. DATA\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");
    A.print("  A");
    B.print("  B");

    std::cout << COLOR_NAME "II. ADDICTION\n" COLOR_RESET;
    std::cout << "---------------------------\n";

    temp = u;
    temp.add(v);
    temp.print("  u + v");
    tempM = A;
    tempM.add(B);
    tempM.print("  A + B");

    std::cout << COLOR_NAME "III. SUBTRACTION\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    temp = u;
    temp.sub(v);
    temp.print("  u - v");
    tempM = A;
    tempM.sub(B);
    tempM.print("  A - B");

    std::cout << COLOR_NAME "IV. SCALING\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    temp = u;
    temp.scl(2);
    temp.print("  2 * u");
    tempM = A;
    tempM.scl(3);
    tempM.print("  3 * A");
}
