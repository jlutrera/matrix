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
void ex00_add();
void ex00_sub();
void ex00_scl();
void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
void ex10();
void ex11();
void ex12();
void ex13();
void ex14();
void ex15();

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

    std::cout << "  I.  BASIC ALGEBRA\n";
    std::cout << "*******************\n";
    std::cout << "  0 : Exercise 00: Addiction\n";
    std::cout << "  1 : Exercise 00: Subtraction\n";
    std::cout << "  2 : Exercise 00: Scaling\n";
    std::cout << "  3 : Exercise 01: Linear Combination\n";
    std::cout << "  4 : Exercise 02: Linear Interpolation\n";

    std::cout << " II.  NORMS AND PRODUCTS\n";
    std::cout << "************************\n";
    std::cout << "  5 : Exercise 03: Dot Product\n";
    std::cout << "  6 : Exercise 04: Norm\n";
    std::cout << "  7 : Exercise 05: Cosine between two vectors\n";
    std::cout << "  8 : Exercise 06: Cross Product\n";

    std::cout << "III.  MATRICIAL ALGEBRA\n";
    std::cout << "***********************\n";
    std::cout << "  9 : Exercise 07: Linear map, Matrix multiplication\n";
    std::cout << " 10 : Exercise 08: Trace\n";
    std::cout << " 11 : Exercise 09: Transpose\n";

    std::cout << " IV.  SOLVING SYSTEMS OF LINEAR EQUATIONS\n";
    std::cout << "*****************************************\n";
    std::cout << " 12 : Exercise 10: Row-Echelon Form\n";
    std::cout << " 13 : Exercise 11: Determinant\n";
    std::cout << " 14 : Exercise 12: Inverse\n";
    std::cout << " 15 : Exercise 13: Rank\n";

    std::cout << "  V.  BONUS\n";
    std::cout << "***********\n";
    std::cout << " 16 : Exercise 14: Projection Matrix\n";
    std::cout << " 17 : Exercise 15: Complex vector spaces\n\n";

    std::cout << " 99  - Quit\n\n";
    std::cout << "Option: ";
}

static void run_test(int option)
{
    switch (option)
    {
        case 0:  ex00_add(); break;
        case 1:  ex00_sub(); break;
        case 2:  ex00_scl(); break;
        case 3:  ex01(); break;
        case 4:  ex02(); break;
        case 5:  ex03(); break;
        case 6:  ex04(); break;
        case 7:  ex05(); break;
        case 8:  ex06(); break;
        case 9:  ex07(); break;
        case 10: ex08(); break;
        case 11: ex09(); break;
        case 12: ex10(); break;
        case 13: ex11(); break;
        case 14: ex12(); break;
        case 15: ex13(); break;
        case 16: ex14(); break;
        case 17: ex15(); break;

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
