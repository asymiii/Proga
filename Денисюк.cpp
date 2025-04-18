#include <iostream> // Чтобы можно было выводить на экран (cout) и вводить с клавиатуры (cin)
#include <cmath>   // Чтобы можно было использовать математические функции, типа sin, cos, pow (возведение в степень)
#define _use_math_defines

using namespace std; // Чтобы не писать std:: перед cout, cin
double getA(const double x, const double y);

double getB(const double x, const double y);


int main() {
    // ===== Исходные данные =====
    const double x = 0.335; // Объявляем переменную x типа double (число с плавающей точкой) и присваиваем ей значение 0.335
    const double y = 0.025; // То же самое для переменной y
    // ===== Вывод результатов вычислений =====
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << getA(x,y) << endl;  // Выводим значение a на экран
    cout << "b = " << getB(x,y);  // Выводим значение b на экран
    return 0;
}
// ===== Вычисление 'a' =====
double getA(const double x, const double y)
{
    return(1 + x + ((pow(x, 2)) / 2) + ((pow(x, 3)) / 3) + ((pow(x, 4)) / 4));
}
// ===== Вычисление 'b' =====
double getB(const double x, const double y)
{
    return(x * (sin(pow(x, 3)) + pow(cos(y), 2)));
}
