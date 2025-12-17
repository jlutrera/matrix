#include "Vector.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

#include <iostream>

void test_ex00() {
    std::cout << "[Exercise 00] Add, Subtract and Scale\n";
    
    Vector v1({1, 2, 3});
    Vector v2({4, 5, 6});

    std::cout << "I. VECTORES\n";
    std::cout << "  DATOS DE PRUEBA\n";
    printOperation("  v1", v1);
    printOperation("  v2", v2);

    std::cout << "  OPERACIONES\n";
    printOperation("  v1 + v2", v1 + v2);
    printOperation("  v1 - v2", v1 - v2);
    printOperation("  2 * v1", v1 * 2);

    
    Matrix m1({{1, 2}, {3, 4}});
    Matrix m2({{5, 6}, {7, 8}});

    std::cout << "II. MATRICES\n";
    std::cout << "  DATOS DE PRUEBA\n";
    printOperation("m1", m1);
    printOperation("m2", m2);
    
    std::cout << "  OPERACIONES\n";
    printOperation("m1 + m2", m1 + m2);
    printOperation("m1 - m2", m1 - m2);
    printOperation("3 * m1", m1 * 3);
}
