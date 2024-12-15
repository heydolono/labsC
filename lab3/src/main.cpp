#include "Vector.h"
#include <iostream>

int main() {
    size_t size = 1000; // Для тестов
    Vector<double> vec(size);

    try {
        vec.InitializeRandom(-100.0, 100.0);
        auto [min_val, min_idx] = vec.FindMin();
        std::cout << "Min value: " << min_val << " at index " << min_idx << std::endl;

        auto [max_val, max_idx] = vec.FindMax();
        std::cout << "Max value: " << max_val << " at index " << max_idx << std::endl;

        std::cout << "Sum: " << vec.CalculateSum() << std::endl;
        std::cout << "Euclidean norm: " << vec.CalculateEuclideanNorm() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
