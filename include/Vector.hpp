#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <iostream>
# include <stdexcept>

class Vector {
    private:
        std::vector<double> _data;

    public:
        Vector(size_t n);
        Vector(const std::vector<double> &data);

        size_t size(void) const;

        Vector operator+(const Vector &other) const;
        Vector operator-(const Vector &other) const;
        Vector operator*(double k) const;

        double operator[](size_t i) const;
        double &operator[](size_t i);

        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};

#endif
