
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/**
* Вычисляет значение функции у = x + x^1/2 + x^1/3 - 2.5
* @param x - аргумент функции
* @retum значение функции в точке х
*/
// Прототипы функций
double functionY (double const x);
/**
* Табулирует функцию на интервале [x0, xend] с шагом step
* @param x0 - начальное значение х
* @param xend - конечное значение х
* @param step - шаг табуляции
*/
void tabulateFunction(double const x0, double const xend, double const step);
/**
* (@brief считывает значение с клавиатуры
* @return введенное значение
*/
double get();
/*＊
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена верно
*/

int main() {
    cout << "введите начальное значение x:";
    double x0 = get();
    cout << "конечное значение x: ";
    double xend = get();
    cout << "шаг ∆x: ";
    double step = get();
    if (step <= 0){
    cout << "шаг должен быть положительным" << endl;
        return 1;
    }
    if (x0 > xend){
        cout << "начальное не может быть больше конечного" << endl;
        return 1;}
            tabulateFunction(x0, xend, step);
        return 0;
}
double functionY(double x) {
    if (x >= 0)
        return x+sqrt(x)+cbrt(x)-2.5;
    return NAN;
}
    void tabulateFunction(double x0, double xend, double step)
{
    cout << "x | y(x)" << endl;
        for (double x = x0; x < xend + step; x += step){
        cout << x <<"|";
  if (x >= 0)
{ double y = functionY (x);}
else
{cout<<"не найдено";}
}
}
double get() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "oшибка: введите корректное число." << endl;
            return 1;
}
    }
    }

