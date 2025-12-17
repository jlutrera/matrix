#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <iostream>
# include <stdexcept>

class Matrix {
    private:
        size_t _rows;
        size_t _cols;
        std::vector<std::vector<double> > _data;

    public:
        Matrix(size_t rows, size_t cols);
        Matrix(const std::vector<std::vector<double> > &data);

        size_t rows(void) const;
        size_t cols(void) const;

        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(double k) const;

        const std::vector<double> &operator[](size_t i) const;
        std::vector<double> &operator[](size_t i);

        friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};

#endif
