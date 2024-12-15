#include "MatrixDense.h"
#include <iostream>

void TestMatrixDense() {
    std::cout << "Testing MatrixDense...\n";

    MatrixDense<double> dense(2, 3);
    dense(0, 0) = 1.0;
    dense(0, 1) = 2.0;
    dense(0, 2) = 3.0;
    dense(1, 0) = 4.0;
    dense(1, 1) = 5.0;
    dense(1, 2) = 6.0;

    std::cout << "MatrixDense content:\n";
    dense.Print();
}
