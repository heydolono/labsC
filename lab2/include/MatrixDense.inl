template <typename T>
void MatrixDense<T>::Import(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка при импорте.");
    }

    file >> _rows >> _cols;
    _data.resize(_rows * _cols);

    for (unsigned int i = 0; i < _rows * _cols; ++i) {
        file >> _data[i];
    }
    file.close();
}

template <typename T>
void MatrixDense<T>::Export(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка при экспорте.");
    }

    file << _rows << " " << _cols << "\n";
    for (unsigned int i = 0; i < _rows; ++i) {
        for (unsigned int j = 0; j < _cols; ++j) {
            file << (*this)(i, j) << " ";
        }
        file << "\n";
    }
    file.close();
}

template <typename T>
void MatrixDense<T>::Print() const {
    for (unsigned int i = 0; i < _rows; ++i) {
        for (unsigned int j = 0; j < _cols; ++j) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "\n";
    }
}
