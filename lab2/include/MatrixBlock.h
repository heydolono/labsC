#ifndef MATRIX_BLOCK_H
#define MATRIX_BLOCK_H

#include "MatrixDense.h"
#include <vector>
#include <memory>

template <typename T = double>
class MatrixBlock : public MatrixBase {
private:
    unsigned int _rows;
    unsigned int _cols;
    std::vector<std::unique_ptr<MatrixDense<T>>> _blocks;

public:
    MatrixBlock(unsigned int rows, unsigned int cols)
        : _rows(rows), _cols(cols), _blocks(rows* cols) {}

    MatrixDense<T>& operator()(unsigned int row, unsigned int col) {
        if (!_blocks[row * _cols + col]) {
            _blocks[row * _cols + col] = std::make_unique<MatrixDense<T>>(1, 1);
        }
        return *_blocks[row * _cols + col];
    }

    const MatrixDense<T>& operator()(unsigned int row, unsigned int col) const {
        if (!_blocks[row * _cols + col]) {
            throw std::runtime_error("Accessing an empty block.");
        }
        return *_blocks[row * _cols + col];
    }

    void Print() const override {
        for (unsigned int i = 0; i < _rows; ++i) {
            for (unsigned int j = 0; j < _cols; ++j) {
                if (_blocks[i * _cols + j]) {
                    _blocks[i * _cols + j]->Print();
                }
                else {
                    std::cout << "Empty ";
                }
            }
            std::cout << "\n";
        }
    }
};

#endif
