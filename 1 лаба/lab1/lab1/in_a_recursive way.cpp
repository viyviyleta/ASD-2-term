#include <iostream>
#include <ctime>
using namespace std;
// ������� ��� ���������� ����� ��������� � ������� ��������
int fibonacci(int n) {
    // ������� ������: ���� n ����� 0 ��� 1, ���������� n
    if (n <= 1) {
        return n;
    }
    // ����������� ������: ���������� ����� ���� ���������� ����� ���������
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(0, "");
    int n;

    cout << "������� ���������� ��������� ������������������ ���������: ";
    cin >> n;
    clock_t start = clock();
    if (n == 0) cout << "������";
    else {
        // ������ ������� �������
        for (int i = 0; i < n; ++i) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;

        // ����� ������� �������
        clock_t end = clock();
        // ���������� ������� ���������� � �������� � �������������
        double durationSeconds = double(end - start) / CLOCKS_PER_SEC;

        cout << "����� ����������: " << durationSeconds << " ������ " << endl;
    }

    return 0;
}
