#include <iostream>

void TestMatrixBlock();
void TestMatrixDense();
void TestMatrixDiagonal();

int main() {
    std::cout << "Running tests...\n";

    TestMatrixBlock();
    TestMatrixDense();
    TestMatrixDiagonal();

    std::cout << "All tests finished.\n";
    return 0;
}
