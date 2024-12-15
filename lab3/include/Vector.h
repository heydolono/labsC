#ifndef VECTOR_H
#define VECTOR_H

#include "VectorBase.h"
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>

template <typename T>
class Vector : public VectorBase {
private:
    T* data; // ��������� �� ������ ������

public:
    // �����������
    Vector(size_t size) : VectorBase(size), data(nullptr) {
        data = new T[size];
    }

    // ����������
    ~Vector() {
        delete[] data;
    }

    // ������ �������������
    void InitializeConstant(T value) {
        for (size_t i = 0; i < n; ++i) {
            data[i] = value;
        }
        is_initialized = true;
    }

    void InitializeRandom(T min, T max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> dist(min, max);

        for (size_t i = 0; i < n; ++i) {
            data[i] = dist(gen);
        }
        is_initialized = true;
    }

    // ������ ������
    std::pair<T, size_t> FindMin() const;
    std::pair<T, size_t> FindMax() const;

    T CalculateSum() const;
    T CalculateMean() const;

    T CalculateEuclideanNorm() const;
    T CalculateManhattanNorm() const;

    // ������� � ������
    void ExportToFile(const std::string& filename) const;
    void ImportFromFile(const std::string& filename);

    // ������������ ������
    T ParallelSum(size_t threads) const;
    T ParallelEuclideanNorm(size_t threads) const;
    T ParallelManhattanNorm(size_t threads) const;
};

#include "Vector.inl"

#endif
