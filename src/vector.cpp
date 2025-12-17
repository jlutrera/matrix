#include "Vector.hpp"
#include "colors.hpp"

Vector::Vector(size_t n) : _data(n, 0.0) {}

Vector::Vector(const std::vector<double> &data) : _data(data) {}

size_t Vector::size(void) const {
    return _data.size();
}

Vector Vector::operator+(const Vector &other) const {
    if (size() != other.size())
        throw std::runtime_error("Vector: dimensiones incompatibles");
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result._data[i] = _data[i] + other._data[i];
    return result;
}

Vector Vector::operator-(const Vector &other) const {
    if (size() != other.size())
        throw std::runtime_error("Vector: dimensiones incompatibles");
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result._data[i] = _data[i] - other._data[i];
    return result;
}

Vector Vector::operator*(double k) const {
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result._data[i] = _data[i] * k;
    return result;
}

double Vector::operator[](size_t i) const {
    return _data[i];
}

double &Vector::operator[](size_t i) {
    return _data[i];
}

std::ostream &operator<<(std::ostream &os, const Vector &v) {
    os << COLOR_BRACE "[ " COLOR_RESET;
    for (size_t i = 0; i < v.size(); i++) {
        os << COLOR_NUM << v[i] << COLOR_RESET;
        if (i + 1 < v.size())
            os << ", ";
    }
    os << COLOR_BRACE " ]" COLOR_RESET;
    return os;
}

