#ifndef VECTORBASE_H
#define VECTORBASE_H

#include <vector>
#include <string>
#include <mutex>
#include <stdexcept>
#include <chrono>

class VectorBase {
protected:
    size_t n;          // ������ �������
    bool is_initialized; // ������ �������������
    std::mutex mtx;      // ������� ��� ������������ ����������

public:
    VectorBase(size_t size) : n(size), is_initialized(false) {}
    virtual ~VectorBase() = default;

    bool IsInitialized() const {
        return is_initialized;
    }

    size_t Size() const {
        return n;
    }
};

#endif
