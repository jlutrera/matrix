#include "Matrix.hpp"
#include "colors.hpp"
#include <sstream>   // para std::ostringstream
#include <iomanip>   // para std::setw

Matrix::Matrix(size_t rows, size_t cols)
: _rows(rows), _cols(cols), _data(rows, std::vector<double>(cols, 0.0)) {}

Matrix::Matrix(const std::vector<std::vector<double> > &data)
: _rows(data.size()), _cols(data[0].size()), _data(data) {}

size_t Matrix::rows(void) const { return _rows; }
size_t Matrix::cols(void) const { return _cols; }

Matrix Matrix::operator+(const Matrix &other) const {
    if (_rows != other._rows || _cols != other._cols)
        throw std::runtime_error("Matrix: dimensiones incompatibles");
    Matrix result(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            result._data[i][j] = _data[i][j] + other._data[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (_rows != other._rows || _cols != other._cols)
        throw std::runtime_error("Matrix: dimensiones incompatibles");
    Matrix result(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            result._data[i][j] = _data[i][j] - other._data[i][j];
    return result;
}

Matrix Matrix::operator*(double k) const {
    Matrix result(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            result._data[i][j] = _data[i][j] * k;
    return result;
}

const std::vector<double> &Matrix::operator[](size_t i) const {
    return _data[i];
}

std::vector<double> &Matrix::operator[](size_t i) {
    return _data[i];
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    size_t rows = m.rows();
    size_t cols = m.cols();

    // Calcular el ancho máximo de cada columna
    std::vector<size_t> col_width(cols, 0);

    for (size_t j = 0; j < cols; j++) {
        for (size_t i = 0; i < rows; i++) {
            std::ostringstream ss;
            ss << m[i][j];
            col_width[j] = std::max(col_width[j], ss.str().size());
        }
    }

    // Función auxiliar para imprimir una fila
    auto print_row = [&](size_t i, bool empty) {
        // Corchete izquierdo
        if (i == 0)
            os << COLOR_BRACE "⎡ " COLOR_RESET;
        else if (i == rows)
            os << COLOR_BRACE "⎣ " COLOR_RESET;
        else
            os << COLOR_BRACE "⎢ " COLOR_RESET;

        // Contenido
        for (size_t j = 0; j < cols; j++) {
            if (empty) {
                os << std::setw(col_width[j]) << " ";
            } else {
                std::ostringstream ss;
                ss << m[i][j];
                os << COLOR_NUM << std::setw(col_width[j]) << ss.str() << COLOR_RESET;
            }

            if (j + 1 < cols)
                os << "  ";
        }

        // Corchete derecho
        if (i == 0)
            os << COLOR_BRACE " ⎤" COLOR_RESET "\n";
        else if (i == rows)
            os << COLOR_BRACE " ⎦" COLOR_RESET "\n";
        else
            os << COLOR_BRACE " ⎥" COLOR_RESET "\n";
    };

    // Imprimir filas reales
    for (size_t i = 0; i < rows; i++)
        print_row(i, false);

    // ✅ Añadir fila vacía dentro de la matriz
    print_row(rows, true);

    return os;
}



