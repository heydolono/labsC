cmake_minimum_required(VERSION 3.10)

project(MatrixProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Заголовочные файлы
include_directories(include)

# Основной исполняемый файл
add_executable(main
    src/main.cpp
)

# Тесты
add_executable(tests
    tests/TestMain.cpp
    tests/TestMatrixBlock.cpp
    tests/TestMatrixDense.cpp
    tests/TestMatrixDiagonal.cpp
)
