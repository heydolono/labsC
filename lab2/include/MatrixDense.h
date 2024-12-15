#ifndef MATRIX_DENSE_H
#define MATRIX_DENSE_H

#include "MatrixBase.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

template <typename T = double>
class MatrixDense : public MatrixBase {
private:
    unsigned int _rows;
    unsigned int _cols;
    std::vector<T> _data;

public:
    MatrixDense(unsigned int rows, unsigned int cols)
        : _rows(rows), _cols(cols), _data(rows* cols, T()) {}

    T& operator()(unsigned int row, unsigned int col) {
        return _data[row * _cols + col];
    }

    const T& operator()(unsigned int row, unsigned int col) const {
        return _data[row * _cols + col];
    }

    void Import(const std::string& filename);
    void Export(const std::string& filename) const;
    void Print() const override;

    unsigned int Rows() const { return _rows; }
    unsigned int Cols() const { return _cols; }
};

#include "MatrixDense.inl"

#endif
