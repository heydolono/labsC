Этот проект предоставляет реализацию различных типов матриц в C++ с поддержкой основных операций, таких как сложение, вычитание, умножение (поэлементное и матричное), транспонирование и экспорт/импорт данных. Также добавлены юнит-тесты для проверки корректности работы функций.

**MatrixDense**: Плотная матрица с поддержкой всех элементов.
**MatrixDiagonal**: Диагональная матрица, где хранятся только элементы диагонали.
**MatrixBlock**: Блочная матрица, состоящая из плотных подматриц (с поддержкой нулевых блоков).

## Основные функции:
Сложение (+), вычитание (-) и поэлементное умножение.
Матричное умножение (*).
Транспонирование матрицы.
Импорт и экспорт данных в/из текстовых файлов.
Проверка работы матриц через модульные тесты.

## Требования
- **Компилятор с поддержкой C++17** или выше.
- **CMake** версии 3.10 или выше.


## Как запустить
1. **Скачайте проект.**
   ```bash
   git clone https://github.com/heydolono/labsC.git
   cd labsC
   ```

2. **Создайте папку для сборки.**
   ```bash
   mkdir build
   cd build
   ```

3. **Сгенерируйте файлы сборки с помощью CMake.**
   ```bash
   cmake ..
   ```

4. **Соберите проект.**
   ```bash
   cmake --build .
   ```

5. **Запустите программу.**
   ```bash
   ./Debug/tests.exe
   ```