#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Вычисляет сумму первых n членов последовательности
 * @param n - количество членов
 * @return сумма членов
 */
double sumFirstN(int n);

/**
 * @brief Вычисляет сумму членов с модулем >= e
 * @param e - минимальное значение модуля
 * @return сумма подходящих членов
 */
double sumGreaterE(double e);

/**
 * @brief Проверяет корректность ввода целого числа
 * @param prompt - приглашение для ввода
 * @return введенное число
 */
int getIntInput(const string& prompt);

/**
 * @brief Проверяет корректность ввода вещественного числа
 * @param prompt - приглашение для ввода
 * @return введенное число
 */
double getDoubleInput(const string& prompt);

int main() {
    // Ввод данных с проверкой
    int n = getIntInput("Введите количество членов n: ");
    double e = getDoubleInput("Введите минимальный модуль e: ");
    
    // Вычисление и вывод результатов
    cout << "Результаты вычислений:" << endl;
    cout << "1. Сумма первых " << n << " членов: " << sumFirstN(n) << endl;
    cout << "2. Сумма членов с модулем >= " << e << ": " << sumGreaterE(e) << endl;
    
    return 0;
}

double sumFirstN(int n) {
    double sum = 0.0;
    double term = 1.0;
    for (int k = 0; k < n; ++k) {
        sum += term;
        term = -term / (k + 1);
    }
    
    return sum;
}

double sumGreaterE(double e) {
    double sum = 0.0;
    double term = 1.0; // Начальное значение для k
    int k = 0;
    
    while (abs(term) >= e) {
        sum += term;
        k++;
        // Рекуррентное соотношение
        term = -term / k;
        
    }
    
    return sum;
}

int getIntInput(const string& prompt) {
    int value;
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value <= 0) {
        cout << "Oшибка: введите корректное число." << endl;
            abort();
        } 
        return value;
        }

double getDoubleInput(const string& prompt) {
     double value;
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value <= 0) {
        cout << "Oшибка: введите корректное число." << endl;
            abort();
        } 
        return value;
        }
