#include "MatrixBlock.h"
#include <iostream>

void TestMatrixBlock() {
    std::cout << "Testing MatrixBlock...\n";

    MatrixBlock<double> block(2, 2);
    block(0, 0) = MatrixDense<double>(2, 2);
    block(0, 0)(0, 0) = 1.0;
    block(0, 0)(0, 1) = 2.0;
    block(0, 0)(1, 0) = 3.0;
    block(0, 0)(1, 1) = 4.0;

    std::cout << "MatrixBlock content:\n";
    block.Print();
}
