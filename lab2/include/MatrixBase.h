#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

class MatrixBase {
public:
    virtual ~MatrixBase() {}
    virtual void Print() const = 0;
};

#endif
