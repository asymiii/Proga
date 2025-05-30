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
double getValue();

int main() {
    cout << "Введите радиус шара R: ";
    double radius = getValue();

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

double getValue() {
    double radius;
    cin >> radius;
    if ((cin.fail());(radius<=0) ) {
        cout << "Только числа и только положительные" << endl;
        abort();
    }
    return radius;
}
