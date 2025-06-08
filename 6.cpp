#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm> 

using namespace std;
/**
 * @enum FM
 * @brief Режимы заполнения массива.
 * Используется для выбора способа заполнения массива:
 * - RANDOM — заполнение случайными числами
 * - MANUAL — заполнение вручную пользователем.
 */
enum FM {
    RANDOM = 1,
    MANUAL = 2
};

/**
 * @brief Заполняет двумерный массив случайными числами в заданном диапазоне
 * @param arr - массив для заполнения
 * @param rows - количество строк
 * @param cols - количество столбцов
 * @param min - минимальное значение
 * @param max - максимальное значение
 */
void fillRandom(int** arr, const size_t rows, const size_t cols, const int min, const int max);

/**
 * @brief Вычисляет сумму элементов первых трех столбцов, заменяя их на квадраты
 * @param arr - массив чисел
 * @param rows - количество строк
 * @param cols - количество столбцов
 */
void processFirstThreeColumns(int** arr, const size_t rows, const size_t cols);

/**
 * @brief Вставляет первую строку после каждой нечетной строки
 * @param arr - массив чисел
 * @param rows - количество строк (будет изменено)
 * @param cols - количество столбцов
 */
int** insertFirstRowAfterOddRows(int** arr, size_t rows, const size_t cols, size_t* newRows);

/**
 * @brief Выводит двумерный массив на экран
 * @param arr - массив чисел
 * @param rows - количество строк
 * @param cols - количество столбцов
 */
void printArray(int** arr, const size_t rows, const size_t cols);

/**
 * @brief Безопасный ввод числа с проверкой
 * @param message - сообщение для пользователя
 * @return - возвращает введенное число
 */
int safeInput(const string& message);

/**
 * @brief Копирует двумерный массив
 * @param src - исходный массив для копирования
 * @param rows - количество строк в массиве
 * @param cols - количество столбцов в массиве
 * @return Возвращает указатель на новый массив, являющийся копией исходного
 */
int** copyArray(int** src, size_t rows, size_t cols);

/**
 * @brief Безопасный ввод положительного числа с проверкой
 * @param message - сообщение для пользователя при вводе
 * @return Возвращает введенное положительное число
 */
size_t safeInputPositive(const string& message);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1 
 */
int main() {
    srand(time(0));
    
    // Ввод диапазона
    int min_val = safeInput("Введите минимальное значение диапазона: ");
    int max_val = safeInput("Введите максимальное значение диапазона: ");
    
    if(min_val > max_val) {
        cout << "Минимальное значение больше максимального. Значения будут поменяны местами." << endl;
        swap(min_val, max_val);
    }
    
    // Используем новую функцию для ввода положительных значений
    size_t rows = safeInputPositive("Введите количество строк: ");
    size_t cols = safeInputPositive("Введите количество столбцов: ");
    
    // Создание массива
    int** arr = new int*[rows];
    for(size_t i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    
    // Заполнение массива
    cout << "Заполнить массив: " << FM::RANDOM << " - Случайными числами, " << FM::MANUAL << " - Вручную. Выберите вариант: ";
    int choice = safeInput("");
    
    switch(FM(choice)) {
        case FM::RANDOM:
            fillRandom(arr, rows, cols, min_val, max_val);
            break;
        case FM::MANUAL:
            cout << "Введите " << rows << "x" << cols << " элементов массива:" << endl;
            for(size_t i = 0; i < rows; i++) {
                for(size_t j = 0; j < cols; j++) {
                    arr[i][j] = safeInput("Элемент [" + to_string(i) + "][" + to_string(j) + "]: ");
                }
            }
            break;
        default:
            cout << "Неверное значение" << endl;
            return 1;
             delete [] arr;
    }
    
    cout << "Исходный массив:" << endl;
    printArray(arr, rows, cols);
    
    // Создаем копию массива для работы
    int** workArr = copyArray(arr, rows, cols);
    size_t workRows = rows;
    
    // 1. Замена элементов первых трех столбцов на их квадраты
    processFirstThreeColumns(workArr, workRows, cols);
    cout << "1. Массив после замены первых трех столбцов на их квадраты:" << endl;
    printArray(workArr, workRows, cols);
    
    // 2. Вставка первой строки после каждой нечетной строки
    size_t newRows;
    int** newArr = insertFirstRowAfterOddRows(workArr, workRows, cols, &newRows);
    workArr = newArr;
    workRows = newRows;
    
    cout << "2. Массив после вставки первой строки после каждой нечетной строки:" << endl;
    printArray(workArr, workRows, cols);
    
    return 0;
    delete [] newArr;
    delete [] workArr;
}

// Остальные функции остаются без изменений
size_t safeInputPositive(const string& message) {
    int value = 0;
    cout << message;
    cin >> value;
    if(cin.fail() || value < 0) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.";
        abort();
    } 
    return value;
}


void fillRandom(int** arr, const size_t rows, const size_t cols, const int min, const int max) {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}


void processFirstThreeColumns(int** arr, const size_t rows, const size_t cols) {
    size_t columnsToProcess = min(cols, static_cast<size_t>(3));
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columnsToProcess; j++) {
            arr[i][j] = arr[i][j] * arr[i][j];
        }
    }
}

int** insertFirstRowAfterOddRows(int** arr, size_t rows, const size_t cols, size_t* newRows) {
    *newRows = rows + (rows + 1) / 2;
    int** newArr = new int*[*newRows];
    
    int* firstRow = new int[cols];
    for(size_t j = 0; j < cols; j++) {
        firstRow[j] = arr[0][j];
    }
    
    size_t newIndex = 0;
    for(size_t i = 0; i < rows; i++) {
        newArr[newIndex] = new int[cols];
        for(size_t j = 0; j < cols; j++) {
            newArr[newIndex][j] = arr[i][j];
        }
        newIndex++;
        
        if(i % 2 == 0) {
            newArr[newIndex] = new int[cols];
            for(size_t j = 0; j < cols; j++) {
                newArr[newIndex][j] = firstRow[j];
            }
            newIndex++;
        }
    }
    
    delete[] firstRow;
    return newArr;
}

void printArray(int** arr, const size_t rows, const size_t cols) {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int safeInput(const string& message) {
    int value = 0;
    cout << message;
    cin >> value;
    if(cin.fail()) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число.";
        abort();
    } 
    return value;
}


int** copyArray(int** src, size_t rows, size_t cols) {
    int** dest = new int*[rows];
    for(size_t i = 0; i < rows; i++) {
        dest[i] = new int[cols];
        for(size_t j = 0; j < cols; j++) {
            dest[i][j] = src[i][j];
        }
    }
    return dest;
}
