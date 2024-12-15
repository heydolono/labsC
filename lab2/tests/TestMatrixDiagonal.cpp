#include "MatrixDiagonal.h"
#include <iostream>

void TestMatrixDiagonal() {
    std::cout << "Testing MatrixDiagonal...\n";

    MatrixDiagonal<double> diagonal(3);
    diagonal(0, 0) = 1.0;
    diagonal(1, 1) = 2.0;
    diagonal(2, 2) = 3.0;

    std::cout << "MatrixDiagonal content:\n";
    diagonal.Print();
}
