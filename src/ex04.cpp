/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:56:22 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/21 14:30:59 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "algebra.hpp"
#include "colors.hpp"
#include <iostream>

void ex04()
{
    using K = float;

    std::cout << COLOR_EX "[Exercise 04] NORM\n" COLOR_RESET;

    Vector<K> u({1, 2});
    Vector<K> v({-5, 6});

    std::cout << COLOR_NAME "I. Data\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    u.print("  u");
    v.print("  v");

    std::cout << COLOR_NAME "II. Results\n" COLOR_RESET;
    std::cout << "---------------------------\n";
    std::cout << "  ||u||₁ = " COLOR_NUM << norm_1(u) << COLOR_RESET "\n";
    std::cout << "  ||u||  = " COLOR_NUM << norm(u) << COLOR_RESET "\n";
    std::cout << "  ||u||∞ = " COLOR_NUM << norm_inf(u) << COLOR_RESET "\n\n";
}
