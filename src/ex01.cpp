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

void ex01() {
    using K = float;

    std::cout << "*****************************************\n";
    std::cout << "* " COLOR_EX "[Exercise 01] Linear Algebra Basics" COLOR_RESET " *\n";
    std::cout << "*****************************************\n";

    Vector<K> u({1, 2, 3});
    Vector<K> v({4, -5, 6});

    std::cout << COLOR_NAME "I. TEST DATA\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");

    std::cout << COLOR_NAME "II. LINEAR COMBINATION\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    Vector<K> lc = linear_combination(2.0f, u, -1.0f, v);
    lc.print("  2u - v");

    std::cout << COLOR_NAME "III. DOT PRODUCT\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  u · v = " COLOR_NUM << dot(u, v) << COLOR_RESET "\n\n";

    std::cout << COLOR_NAME "IV. NORMS\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  ||u||₁   = " COLOR_NUM << norm_1(u) << COLOR_RESET "\n";
    std::cout << "  ||u||₂   = " COLOR_NUM << norm_2(u) << COLOR_RESET "\n";
    std::cout << "  ||u||∞   = " COLOR_NUM << norm_inf(u) << COLOR_RESET "\n\n";

    std::cout << COLOR_NAME "V. ANGLE BETWEEN VECTORS\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  angle(u, v) = " COLOR_NUM << angle(u, v) << COLOR_RESET " rad\n\n";

    std::cout << COLOR_NAME "VI. COSINE SIMILARITY\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  cos(u, v) = " COLOR_NUM << cosine_similarity(u, v) << COLOR_RESET "\n\n";
}

