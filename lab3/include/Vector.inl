#ifndef VECTOR_INL
#define VECTOR_INL

#include <algorithm>
#include <numeric>
#include <cmath>
#include <thread>

// ����� �������
template <typename T>
std::pair<T, size_t> Vector<T>::FindMin() const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    auto min_it = std::min_element(data, data + n);
    return { *min_it, static_cast<size_t>(min_it - data) };
}

// ����� ��������
template <typename T>
std::pair<T, size_t> Vector<T>::FindMax() const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    auto max_it = std::max_element(data, data + n);
    return { *max_it, static_cast<size_t>(max_it - data) };
}

// ����� ���������
template <typename T>
T Vector<T>::CalculateSum() const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    return std::accumulate(data, data + n, T(0));
}

// ������� ��������
template <typename T>
T Vector<T>::CalculateMean() const {
    return CalculateSum() / static_cast<T>(n);
}

// ��������� �����
template <typename T>
T Vector<T>::CalculateEuclideanNorm() const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    T sum_of_squares = std::accumulate(data, data + n, T(0), [](T acc, T val) {
        return acc + val * val;
        });
    return std::sqrt(sum_of_squares);
}

// ������������� �����
template <typename T>
T Vector<T>::CalculateManhattanNorm() const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    return std::accumulate(data, data + n, T(0), [](T acc, T val) {
        return acc + std::abs(val);
        });
}

// ������� � ����
template <typename T>
void Vector<T>::ExportToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::ios_base::failure("������ �������� ��� ������");
    }

    for (size_t i = 0; i < n; ++i) {
        file << data[i] << '\n';
    }
}

// ������ �� �����
template <typename T>
void Vector<T>::ImportFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::ios_base::failure("������ �������� ��� ������");
    }

    for (size_t i = 0; i < n; ++i) {
        file >> data[i];
    }
    is_initialized = true;
}

// ������������ ����������
template <typename T>
T Vector<T>::ParallelSum(size_t threads) const {
    if (!is_initialized) {
        throw std::logic_error("������ �� ���������������");
    }

    T total_sum = 0;
    size_t chunk_size = n / threads;

    auto sum_chunk = [&](size_t start, size_t end, T& result) {
        result = std::accumulate(data + start, data + end, T(0));
        };

    std::vector<std::thread> thread_pool;
    std::vector<T> results(threads, 0);

    for (size_t i = 0; i < threads; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == threads - 1) ? n : start + chunk_size;
        thread_pool.emplace_back(sum_chunk, start, end, std::ref(results[i]));
    }

    for (auto& thread : thread_pool) {
        thread.join();
    }

    total_sum = std::accumulate(results.begin(), results.end(), T(0));
    return total_sum;
}

#endif
