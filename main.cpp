/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:35:20 by jutrera-          #+#    #+#             */
/*   Updated: 2025/12/20 11:35:20 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>

// Prototypes for exercise functions
void ex00();
void ex01_09();
// void ex02();
// void ex03();
// void ex04();
// void ex05();
// void ex06();
// void ex07();
// void ex08();
// void ex09();
// void ex10();
// void ex11();
// void ex12();
// void ex13();
// void ex14();
// void ex15();

static void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

static void wait_key()
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

static void print_menu()
{
    std::cout << "\n==============================\n";
    std::cout << "     ENTER THE MATRIX - TESTS\n";
    std::cout << "==============================\n";
    std::cout << "Select an option:\n\n";

    std::cout << "  0  - Exercise 00: Add, Subtract, Scale\n";
    std::cout << "  1  - Exercise 01: Linear Combination\n";
    std::cout << "     - Exercise 02: Linear Interpolation\n";
    std::cout << "     - Exercise 03: Dot Product\n";
    std::cout << "     - Exercise 04: Norm\n";
    std::cout << "     - Exercise 05: Cosine\n";
    std::cout << "     - Exercise 06: Cross Product\n";
    std::cout << "     - Exercise 07: Linear map, Matrix multiplication\n";
    std::cout << "     - Exercise 08: Trace\n";
    std::cout << "     - Exercise 09: Transpose\n";
    std::cout << "  2  - Exercise 10: Row-echelon Form\n";
    std::cout << "     - Exercise 11: Determinant\n";
    std::cout << "     - Exercise 12: Inverse\n";
    std::cout << "  3  - Exercise 13: Rank\n";
    std::cout << "  4  - Exercise 14: Bonus: Projection Matrix\n\n";
    std::cout << "  5  - Exercise 15: Bonus: Complex vector spaces\n\n";

    std::cout << " 99  - Quit\n\n";
    std::cout << "Option: ";
}

static void run_test(int option)
{
    switch (option)
    {
        case 0:  ex00(); break;
        case 1:  ex01_09(); break;
        // case 2:  ex02(); break;
        // case 3:  ex03(); break;
        // case 4:  ex04(); break;
        // case 5:  ex05(); break;
        // case 6:  ex06(); break;
        // case 7:  ex07(); break;
        // case 8:  ex08(); break;
        // case 9:  ex09(); break;
        // case 10: ex10(); break;
        // case 11: ex11(); break;
        // case 12: ex12(); break;
        // case 13: ex13(); break;
        // case 14: ex14(); break;
        // case 15: ex15(); break;

        default:
            std::cout << "Invalid option\n";
            break;
    }
}

int main()
{
    while (true)
    {
        clear_screen();
        print_menu();

        int option;
        std::cin >> option;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (option == 99)
        {
            clear_screen();
            std::cout << "Exiting...\n";
            break;
        }

        clear_screen();
        run_test(option);

        std::cout << "\n--- End of test ---\n";
        wait_key();
    }

    return 0;
}
