#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm> // для swap

using namespace std;

/**
 * @brief - Заполняет массив случайными числами в заданном диапазоне
 * @param arr - массив для заполнения
 * @param n - размер массива
 * @param min - минимальное значение
 * @param max - максимальное значение
 */
void fillRandom(int* arr, size_t n, int min, int max);

/**
 * @brief - Вычисляет сумму элементов с нечетными индексами
 * @param arr - массив чисел
 * @param n - размер массива
 * @return - возвращает сумму элементов
 */
int sumOddIndexes(const int* arr, size_t n);

/**
 * @brief - Подсчитывает элементы больше A и кратные 5
 * @param arr - массив чисел
 * @param n - размер массива
 * @param A - заданное число для сравнения
 * @return - возвращает количество элементов
 */
int countElements(const int* arr, size_t n, int A);

/**
 * @brief - Делит элементы с четными номерами на первый элемент
 * @param arr - массив чисел
 * @param n - размер массива
 */
void divideEvenNumbered(int* arr, size_t n);

/**
 * @brief - Выводит массив на экран
 * @param arr - массив чисел
 * @param n - размер массива
 */
void printArray(const int* arr, size_t n);

/**
 * @brief - Безопасный ввод числа с проверкой
 * @param message - сообщение для пользователя
 * @return - возвращает введенное число
 */
int safeInput(const string& message);

int main() {
    srand(time(0));
    
    // Ввод диапазона
    int min_val = safeInput("Введите минимальное значение диапазона: ");
        if (min_val<(-10)){
        cout<<("Ошибка");
        abort();
    }
    int max_val = safeInput("Введите максимальное значение диапазона: ");
        if (max_val>(20)){
        cout<<("Ошибка");
        abort();
    }
    
    if(min_val > max_val) {
        cout << "Минимальное значение больше максимального.";
    }
    
    size_t n = safeInput("Введите размер массива: ")
    int* arr = new int[n];
    int* work_arr = new int[n];
    
    // Заполнение массива
    cout << "Заполнить массив:1. Случайными числами 2. Вручную Выберите вариант: ";
    int choice = safeInput("");
    
    if(choice == 1) {
        fillRandom(arr, n, min_val, max_val);
    } else {
        cout << "Введите " << n << " элементов массива:";
        for(size_t i = 0; i < n; i++) {
            arr[i] = safeInput("Элемент " + to_string(i) + ": ");
        }
    }
    copy(arr, arr + n, work_arr);
    
    cout << "Исходный массив: ";
    printArray(arr, n);
     
    cout << "1. Сумма элементов с нечетными индексами: " 
         << sumOddIndexes(work_arr, n) << endl;
 
    int A = safeInput("Введите число A: ");
    cout << "2. Количество элементов > " << A << " и кратных 5: " 
         << countElements(work_arr, n, A) << endl;
 
    if(work_arr[0] != 0) {
        divideEvenNumbered(work_arr, n);
        cout << "3. Массив после деления элементов с четными номерами: ";
        printArray(work_arr, n);
    } else {
        cout << "3. Ошибка: первый элемент равен 0, деление невозможно";
        abort();
    }
    
}

void fillRandom(int* arr, size_t n, int min, int max) {
    for(size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int sumOddIndexes(const int* arr, size_t n) {
    int sum = 0;
    for(size_t i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int countElements(const int* arr, size_t n, int A) {
    int count = 0;
    for(size_t i = 0; i < n; i++) {
        if(arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

void divideEvenNumbered(int* arr, size_t n) {
    int first = arr[0];
    for(size_t i = 1; i < n; i += 2) {
        arr[i] /= first;
    }
}

void printArray(const int* arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int safeInput(const string& message) {
    int value;
    cout << message;
    cin >> value;
    if(cin.fail()) {
    cout << "Ошибка ввода. Пожалуйста, введите целое число.";
    abort();
        } 
    return value;
    }
