 Это проект, реализующий класс Vector, предназначенный для работы с векторами динамической размерности. Класс предоставляет удобный интерфейс для работы с большими векторами с различными операциями, включая последовательные и параллельные вычисления

## Функциональные возможности:
Динамическое выделение памяти: Класс позволяет работать с векторами любых типов данных (шаблонный класс).
Инициализация:
Константным значением.
Случайными числами в заданном диапазоне (включая отрицательные).
Экспорт/импорт в файл.

## Операции:
Нахождение минимального и максимального значения, их индексов.
Сумма всех элементов.
Среднее арифметическое.
Вычисление евклидовой и манхэттенской норм.
Скалярное произведение двух векторов.
Параллельные вычисления: Все операции поддерживают выполнение с помощью потоков (std::thread), количество потоков задаётся пользователем.
Замеры времени: Для каждой операции фиксируется время выполнения (как для последовательной, так и для параллельной реализации).

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
   ./Debug/main.exe
   ```