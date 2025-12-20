/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:50:22 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 22:50:22 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "utilities.hpp"
#include "colors.hpp"
#include <iostream>

void ex01_09()
{
    using K = float;

    std::cout << "*****************************************\n";
    std::cout << "* " COLOR_EX "[Exercise 01] Linear Algebra Basics" COLOR_RESET " *\n";
    std::cout << "*****************************************\n";

    Vector<K> u({1, 2, 3});
    Vector<K> v({4, -5, 6});
    Matrix<K> A({{1, 2, 3}, {4, 5, 6}});
    Matrix<K> B({{7, 8, 9}, {10, 11, 12}});

    std::cout << COLOR_NAME "I. DATA\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");
    A.print("  A");
    B.print("  B");

    std::cout << COLOR_NAME "II. LINEAR COMBINATION\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Vector<K> lc = linear_combination(2.0f, u, -1.0f, v);
    lc.print("  2u - v");

    std::cout << COLOR_NAME "III. LINEAR INTERPOLATION\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Vector<K> lerp_vec = lerp(u, v, 0.25);
    lerp_vec.print("  lerp(u, v, 0.25)");
    Matrix<K> lerp_mat = lerp(A, B, 0.5);
    lerp_mat.print("  lerp(A, B, 0.5)");

    std::cout << COLOR_NAME "IV. DOT PRODUCT\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  u · v = " COLOR_NUM << dot(u, v) << COLOR_RESET "\n\n";

    std::cout << COLOR_NAME "V. NORMS\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  ||u||₁ = " COLOR_NUM << norm_1(u) << COLOR_RESET "\n";
    std::cout << "  ||u||  = " COLOR_NUM << norm(u) << COLOR_RESET "\n";
    std::cout << "  ||u||∞ = " COLOR_NUM << norm_inf(u) << COLOR_RESET "\n\n";

    std::cout << COLOR_NAME "VI. COSINE BETWEEN VECTORS\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  angle_cos(u, v) = " COLOR_NUM << angle_cos(u, v) << COLOR_RESET " rad\n\n";

    std::cout << COLOR_NAME "VII. CROSS PRODUCT\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Vector<K> cross = cross_product(u, v);
    cross.print("  u x v");

    std::cout << COLOR_NAME "VIII. MATRIX MULTIPLICATION\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Matrix<K> C = mul_mat(A);
    C.print("  A * B");

    std::cout << COLOR_NAME "IX. LINEAR MAP\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Vector<K> w({1, 0, -1});
    Vector<K> mapped = mul_vec(w);
    mapped.print("  A * w");

    std::cout << COLOR_NAME "X. TRACE\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Matrix<K> D({{1, 2}, {3, 4}});
    D.print("  D");
    std::cout << "  trace(D) = " COLOR_NUM << trace(D) << COLOR_RESET "\n\n";

    std::cout << COLOR_NAME "XI. TRANSPOSE\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Matrix<K> D_T = transpose(D);
    D_T.print("  D^T");
}
