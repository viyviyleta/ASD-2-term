//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int main() {
//    setlocale(0, "");
//    int n;
//    cout << "Введите число n: ";
//    cin >> n;
//
//    clock_t start = clock();
//
//    if (n == 1) {
//        cout << 0;
//    }
//    else if (n == 2) {
//        cout << 1;
//    }
//    else if (n > 2) {
//        cout << 0 << " " << 1 << " ";
//        int a = 0, b = 1, c;
//        for (int i = 3; i <= n; i++) {
//            c = a + b;
//            a = b;
//            b = c;
//            cout << b << " ";
//        }
//    }
//    
//    clock_t end = clock();
//    double seconds = double(end - start) / CLOCKS_PER_SEC;
//
//    int minutes = seconds / 60;
//    seconds -= minutes * 60;
//
//    cout << endl << "Время выполнения: " << minutes << " минут " << seconds << " секунд." << endl;
//    return 0;
//}
