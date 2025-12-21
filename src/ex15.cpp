/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex15.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:20:00 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/21 14:31:43 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include "vector.hpp"
#include "algebra.hpp"
#include "colors.hpp"
#include <iostream>

void ex15()
{
    using R = float;
    using C = std::complex<R>;

    std::cout << COLOR_EX "[Exercise 15] COMPLEX VECTOR SPACES\n" COLOR_RESET;

    // I. Vectores complejos
    std::cout << COLOR_NAME "I. Complex vectors\n" COLOR_RESET;
    std::cout << "-------------------\n";

    Vector<C> v1({ C(1, 2), C(-3, 0), C(0, -1) });
    Vector<C> v2({ C(0, 1), C(2, -1), C(1, 0) });

    v1.print("  v1");
    v2.print("  v2");

    Vector<C> v_sum = v1;
    v_sum.add(v2);
    v_sum.print("  v1 + v2");

    Vector<C> v_diff = v1;
    v_diff.sub(v2);
    v_diff.print("  v1 - v2");

    Vector<C> v_scl = v1;
    v_scl.scl(C(0, 1)); // multiplicar por i
    v_scl.print("  i * v1");

    std::cout << "\n";

    // II. Matrices complejas y mul_vec
    std::cout << COLOR_NAME "II. Complex matrices and mul_vec\n" COLOR_RESET;
    std::cout << "----------------------------------\n";

    Matrix<C> A({
        { C(1, 0),  C(0, 1) },
        { C(2, -1), C(-1, 2) }
    });

    Vector<C> x({ C(1, 0), C(0, 1) });

    A.print("  A");
    x.print("  x");

    Vector<C> Ax = A.mul_vec(x);
    Ax.print("  A * x");

    std::cout << "\n";

    // III. Determinante e inversa en complejos
    std::cout << COLOR_NAME "III. Determinant and inverse (complex)\n" COLOR_RESET;
    std::cout << "----------------------------------------\n";

    Matrix<C> B({
        { C(1, 1), C(2, -1) },
        { C(0, -1), C(1, 0) }
    });

    B.print("  B");

    try
    {
        C detB = B.determinant();
        std::cout << "  det(B) = " COLOR_NUM << detB << COLOR_RESET "\n\n";

        Matrix<C> B_inv = B.inverse();
        B_inv.print("  B^{-1}");
    }
    catch (const std::exception& e)
    {
        std::cout << COLOR_ERR "  Error: " << e.what() << COLOR_RESET "\n";
    }
}
