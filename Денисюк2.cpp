#include <iostream>
#include <cmath>
#include <limits> 

using namespace std;

/**
 * @brief - Функция для вычисления объема шара
 * @param radius - радиус шара
 * @return - возвращает объем шара
 */
double calculateVolume(const double radius);

/**
 * @brief - Функция для вычисления площади поверхности шара
 * @param radius - радиус шара
 * @return - возвращает площадь поверхности шара
 */
double calculateSurfaceArea(const double radius);

/**
 * @brief - Проверяет, является ли ввод корректным числом
 * @return - возвращает введенное число, если оно корректно
 */
double getValidatedInput();

/**
 * @brief - Точка входа в программу
 * @return - возвращает 0, если программа выполнена корректно
 */
int main() {
    cout << "Введите радиус шара R: ";
    double radius = getValidatedInput();

    cout << "Результаты вычислений:" << endl;
    cout << "Объем шара: " << calculateVolume(radius) << endl;
    cout << "Площадь поверхности шара: " << calculateSurfaceArea(radius) << endl;

    return 0;
}

double calculateVolume(const double radius) {
    return (4.0 / 3.0) * 3.14 * pow(radius, 3);
}

double calculateSurfaceArea(const double radius) {
    return 4 * 3.14 * pow(radius, 2);
}

double getValidatedInput() {
    double input;
    while (true) {
        cin >> input;
        if (cin.fail()) { // Если ввод не является числом
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            cout << "Ошибка! Введите число: ";
        } else {
            return input;
        }
    }
}
