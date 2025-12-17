#include <iostream>
#include <cstdlib>
#include <limits>

// Prototipos de tests (debes implementarlos en test/*.cpp)
void test_ex00();
void test_ex01();
void test_ex02();
// void test_ex03();
// void test_ex04();
// void test_ex05();
// void test_ex06();
// void test_ex07();
// void test_ex08();
// void test_ex09();
// void test_ex10();
// void test_ex11();
// void test_ex12();
// void test_ex13();
// void test_ex14();

static void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void wait_key() {
    std::cout << "\nPulsa ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

static void print_menu() {
    std::cout << "\n==============================\n";
    std::cout << "     ENTER THE MATRIX - TESTS\n";
    std::cout << "==============================\n";
    std::cout << "Selecciona un ejercicio:\n\n";

    std::cout << "  0  - Exercise 00: Add, Subtract, Scale\n";
    std::cout << "  1  - Exercise 01: Linear Combination\n";
    std::cout << "  2  - Exercise 02: Linear Interpolation\n";
    std::cout << "  3  - Exercise 03: Dot Product\n";
    std::cout << "  4  - Exercise 04: Norm\n";
    std::cout << "  5  - Exercise 05: Cosine\n";
    std::cout << "  6  - Exercise 06: Cross Product\n";
    std::cout << "  7  - Exercise 07: Matrix Multiplication\n";
    std::cout << "  8  - Exercise 08: Trace\n";
    std::cout << "  9  - Exercise 09: Transpose\n";
    std::cout << " 10  - Exercise 10: Row-echelon Form\n";
    std::cout << " 11  - Exercise 11: Determinant\n";
    std::cout << " 12  - Exercise 12: Inverse\n";
    std::cout << " 13  - Exercise 13: Rank\n";
    std::cout << " 14  - Exercise 14: Projection Matrix\n\n";

    std::cout << " 99  - Salir\n\n";
    std::cout << "Opción: ";
}

static void run_test(int option) {
    switch (option) {
        case 0:  test_ex00(); break;
        case 1:  test_ex01(); break;
        case 2:  test_ex02(); break;
        // case 3:  test_ex03(); break;
        // case 4:  test_ex04(); break;
        // case 5:  test_ex05(); break;
        // case 6:  test_ex06(); break;
        // case 7:  test_ex07(); break;
        // case 8:  test_ex08(); break;
        // case 9:  test_ex09(); break;
        // case 10: test_ex10(); break;
        // case 11: test_ex11(); break;
        // case 12: test_ex12(); break;
        // case 13: test_ex13(); break;
        // case 14: test_ex14(); break;

        default:
            std::cout << "Opción no válida.\n";
            break;
    }
}

int main() {
    while (true) {
        clear_screen();
        print_menu();

        int option;
        std::cin >> option;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (option == 99) {
            clear_screen();
            std::cout << "Saliendo...\n";
            break;
        }

        clear_screen();
        run_test(option);

        std::cout << "\n--- Fin del test ---\n";
        wait_key();
    }

    return 0;
}
