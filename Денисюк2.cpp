#include <iostream>
#include <cmath>
#include <limits> 
#include <cstdlib>
using namespace std;

/**
 * @brief - Функция для вычисления объема шара
 * @param radius - радиус шара
 * @return - возвращает объем шара
 */
double Volume(const double radius);

/**
 * @brief - Функция для вычисления площади поверхности шара
 * @param radius - радиус шара
 * @return - возвращает площадь поверхности шара
 */
double Area(const double radius);

/**
 * @brief - Проверяет, является ли ввод корректным числом
 * @return - возвращает введенное число, если оно корректно
 */

int main() {
    cout << "Введите радиус шара R: ";
    double radius;
    // Проверка ввода на корректность (только положительные числа)
    while (!(cin >> radius) || radius <= 0) { // Пока ввод некорректен (не число или <= 0)
        cout << "Ошибка! Введите положительное число: "; // Выводим сообщение об ошибке
        cin.clear(); // Очищаем флаг ошибки у cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Удаляем некорректный ввод из потока
    }
    cout << "Результаты вычислений:" << endl;
    cout << "Объем шара: " << Volume(radius) << endl;
    cout << "Площадь поверхности шара: " << Area(radius) << endl;

    return 0;
}

double Volume(const double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double Area(const double radius) {
    return 4 * M_PI * pow(radius, 2);
}
