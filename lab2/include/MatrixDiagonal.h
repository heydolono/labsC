#ifndef MATRIX_DIAGONAL_H
#define MATRIX_DIAGONAL_H

#include "MatrixBase.h"
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T = double>
class MatrixDiagonal : public MatrixBase {
private:
    unsigned int _size;
    std::vector<T> _data;

public:
    MatrixDiagonal(unsigned int size)
        : _size(size), _data(size, T()) {}

    T& operator()(unsigned int row, unsigned int col) {
        if (row != col) {
            throw std::out_of_range("Accessing non-diagonal element.");
        }
        return _data[row];
    }

    const T& operator()(unsigned int row, unsigned int col) const {
        if (row != col) {
            throw std::out_of_range("Accessing non-diagonal element.");
        }
        return _data[row];
    }

    void Print() const override {
        for (unsigned int i = 0; i < _size; ++i) {
            for (unsigned int j = 0; j < _size; ++j) {
                std::cout << (i == j ? _data[i] : 0) << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif
