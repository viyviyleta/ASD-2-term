#include <iostream>
using namespace std;

int main()
{
    setlocale(0, ""); 

    int N, N1, maxSteps = 1, result, order = 1, flag = 0, steps = 0; 

    bool answer = 0; 

    cout << "Введите N(от 1 до N) и загадайте число X: ";
    cin >> N; 

    N1 = N; 

    // Определение максимального количества шагов для бинарного поиска
    while (N1 / 2 > 0)
    {
        N1 /= 2;
        maxSteps++;
    }

    // Выделение памяти под массив
    int* array = new int[maxSteps];

    int minValue = 1, maxValue = N;

    if (N % 2 == 0) {
        result = N / 2; 
    }
    else {
        result = (N + 1) / 2; 
    }

    if (N == 0)
    {
        cout << "Введено некорректное значение.";
        return 0;
    }
    else
        if (N == 1)
        {
            cout << "Ваше число 1" << endl;
            cout << "Максимальное количество шагов при бинарном поиске равно: " << 1 << "\n";
        }
        else
        {
            while (!answer)
            {
                cout << "\nВаше загаданное число равно: " << result;
                cout << "\nНажмите 1, если число угадано верно";
                cout << "\nНажмите 2, если загаданное число меньше";
                cout << "\nНажмите 3, если загаданное число больше\n";

                while (flag != 1)
                {
                    array[0] = result;
                    flag++;
                }

                int choice;
                cin >> choice;

                steps++;

                switch (choice)
                {
                case 1: // Если число угадано верно
                    cout << "Максимальное количество шагов при бинарном поиске равно: " << maxSteps << "\n";
                    cout << "Промежуточные шаги: ";
                    for (int i = 0; i < order; i++)
                    {
                        cout << array[i] << ' ';
                    }
                    cout << "\nКоличество шагов пользователя: " << steps << endl;
                    answer = 1;
                    break;

                case 2: // Если загаданное число меньше
                    maxValue = result;
                    result = (maxValue + minValue) / 2;
                    for (int i = order; i < order + 1; i++)
                    {
                        array[i] = result;
                    }
                    order++;
                    break;

                case 3: // Если загаданное число больше
                    minValue = result;
                    result = (maxValue + minValue) / 2;
                    for (int i = order; i < order + 1; i++)
                    {
                        array[i] = result;
                    }
                    order++;
                    break;

                default: // Если введено некорректное значение
                    cout << "Введено неверное значение.\n";
                    break;
                }

            }

            delete[] array;
        }
    return 0; 
}
