#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief - Заполняет массив случайными числами в заданном диапазоне
 * @param arr - массив для заполнения
 * @param n - размер массива
 * @param min - минимальное значение
 * @param max - максимальное значение
 */
void fillRandom(int arr[], int n, int min, int max);

/**
 * @brief - Вычисляет сумму элементов с нечетными индексами
 * @param arr - массив чисел
 * @param n - размер массива
 * @return - возвращает сумму элементов
 */
int sumOddIndexes(int arr[], int n);

/**
 * @brief - Подсчитывает элементы больше A и кратные 5
 * @param arr - массив чисел
 * @param n - размер массива
 * @param A - заданное число для сравнения
 * @return - возвращает количество элементов
 */
int countElements(int arr[], int n, int A);

/**
 * @brief - Делит элементы с четными номерами на первый элемент
 * @param arr - массив чисел
 * @param n - размер массива
 */
void divideEvenNumbered(int arr[], int n);

/**
 * @brief - Выводит массив на экран
 * @param arr - массив чисел
 * @param n - размер массива
 */
void printArray(int arr[], int n);

int main() {
    srand(time(0));
    const int MIN = -10, MAX = 20;
    int n, A;
    
    cout << "Введите размер массива: ";
    cin >> n;
    
    int* arr = new int[n];
    fillRandom(arr, n, MIN, MAX);
    
    cout << "Сформированный массив: ";
    printArray(arr, n);
    
    cout << "1. Сумма элементов с нечетными индексами: " 
         << sumOddIndexes(arr, n) << endl;
    
    cout << "Введите число A: ";
    cin >> A;
    cout << "2. Количество элементов > " << A << " и кратных 5: " 
         << countElements(arr, n, A) << endl;
    
    if(arr[0] != 0) {
        divideEvenNumbered(arr, n);
        cout << "3. Массив после деления элементов с четными номерами: ";
        printArray(arr, n);
    } else {
        cout << "3. Ошибка: первый элемент равен 0, деление невозможно" << endl;
    }
    
    delete[] arr;
    return 0;
}

void fillRandom(int arr[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int sumOddIndexes(int arr[], int n) {
    int sum = 0;
    for(int i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int countElements(int arr[], int n, int A) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

void divideEvenNumbered(int arr[], int n) {
    for(int i = 1; i < n; i += 2) {
        arr[i] /= arr[0]; 
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}