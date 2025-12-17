#pragma once
#include <iostream>

template<typename T>
void printOperation(const std::string &op, const T &result) {
    std::cout << op << "\n" << result << "\n\n";
}
