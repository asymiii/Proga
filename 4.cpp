#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления факториала
double factorial(int k) {
    double result = 1;
    for (int i = 1; i <= k; i++) {
        result *= i;
    }
    return result;
}

// Функция a) - сумма первых n членов
double sum_n_terms(int n) {
    double sum = 0;
    for (int k = 0; k <= n; k++) {
        sum += pow(-1, k) / factorial(k);
    }
    return sum;
}

// Функция b) - сумма членов с |член| >= e
double sum_above_e(double e) {
    double sum = 0;
    int k = 0;
    double term;
    
    while (true) {
        term = pow(-1, k) / factorial(k);
        if (fabs(term) < e) break;
        sum += term;
        k++;
    }
    
    return sum;
}

int main() {
    int n;
    double e;
    
 cout << "Введите n (целое положительное число): ";
    cin >> n;
    while (n <= 0) {
        cout << "Ошибка! n должно быть положительным. Введите снова: ";
        cin >> n;
    }
 cout << "Введите e (целое положительное число): ";
    cin >> e;
    while (e <= 0) {
        cout << "Ошибка! e должно быть положительным. Введите снова: ";
        cin >> e;
    }
    
    // Вывод результатов
    cout << "a) Сумма первых " << n << " членов: " << sum_n_terms(n) << endl;
    cout << "b) Сумма членов  не меньших по модулю: " << e << ": " << sum_above_e(e) << endl;
    
    return 0;
}
