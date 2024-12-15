#include "MatrixDense.h"
#include "MatrixDiagonal.h"
#include "MatrixBlock.h"
#include <iostream>

int main() {
    // Test MatrixDense
    MatrixDense<double> dense(2, 2);
    dense(0, 0) = 1.0;
    dense(0, 1) = 2.0;
    dense(1, 0) = 3.0;
    dense(1, 1) = 4.0;
    dense.Print();

    // Test MatrixDiagonal
    MatrixDiagonal<double> diagonal(3);
    diagonal(0, 0) = 1.0;
    diagonal(1, 1) = 2.0;
    diagonal(2, 2) = 3.0;
    diagonal.Print();

    // Test MatrixBlock
    MatrixBlock<double> block(2, 2);
    block(0, 0) = MatrixDense<double>(2, 2);
    block(0, 0)(0, 0) = 1.0;
    block(0, 0)(0, 1) = 2.0;
    block(0, 0)(1, 0) = 3.0;
    block(0, 0)(1, 1) = 4.0;

    block.Print();

    return 0;
}
