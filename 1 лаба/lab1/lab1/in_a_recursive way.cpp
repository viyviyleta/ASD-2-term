#include <iostream>
#include <ctime>
using namespace std;
// Функция для вычисления числа Фибоначчи с помощью рекурсии
int fibonacci(int n) {
    // Базовый случай: если n равно 0 или 1, возвращаем n
    if (n <= 1) {
        return n;
    }
    // Рекурсивный случай: возвращаем сумму двух предыдущих чисел Фибоначчи
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(0, "");
    int n;

    cout << "Введите количество элементов последовательности Фибоначчи: ";
    cin >> n;
    clock_t start = clock();
    if (n == 0) cout << "Ошибка";
    else {
        // Начало отсчета времени
        for (int i = 0; i < n; ++i) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;

        // Конец отсчета времени
        clock_t end = clock();
        // Вычисление времени выполнения в секундах и миллисекундах
        double durationSeconds = double(end - start) / CLOCKS_PER_SEC;

        cout << "Время выполнения: " << durationSeconds << " секунд " << endl;
    }

    return 0;
}
