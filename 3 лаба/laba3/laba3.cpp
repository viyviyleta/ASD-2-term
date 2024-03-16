#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void qsortRecursive(int* array, int N);

int main()
{
	setlocale(0, "");

	int N;

	cout << "Введите число N: ";
	cin >> N;

	int* array = new int[N];
	int* arrayB = new int[N];
	int* arrayC = new int[N];
	int* arrayD = new int[N];
	int* arrayE = new int[N];

	srand(time(NULL));

	cout << "Исходный массив: ";

	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << ' ';
	}

	for (int i = 0; i < N; i++)
	{
		arrayB[i] = array[i];
		
		arrayC[i] = array[i];
		
		arrayD[i] = array[i];
		
		arrayE[i] = array[i];
	}
	




	int tempB;
	cout << "\n\nМассив B: "; //пузырёк
	auto startArrayB = high_resolution_clock::now();
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arrayB[j] > arrayB[j + 1]) {
				
				tempB = arrayB[j];
				arrayB[j] = arrayB[j + 1];
				arrayB[j + 1] = tempB;
				
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arrayB[i] << ' ';
	}
	auto stopArrayB = high_resolution_clock::now();
	auto differenceArrayB = duration_cast<microseconds>(stopArrayB - startArrayB);
	cout << "\nВремя сортировкой пузырьком: " << differenceArrayB.count() << " микросекунд.";





	cout << "\n\nМассив C: "; //вставка
	int tempC, current_element;
	auto startArrayC = high_resolution_clock::now();
	for (int i = 1; i < N; i++)
	{
		current_element = arrayC[i];
		for (int j = i - 1; j >= 0 && arrayC[j] > current_element; j--)
		{
			tempC = arrayC[j + 1];
			arrayC[j + 1] = arrayC[j];
			arrayC[j] = tempC;
			
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arrayC[i] << ' ';
	}
	auto stopArrayC = high_resolution_clock::now();
	auto differenceArrayC = duration_cast<microseconds>(stopArrayC - startArrayC);
	cout << "\nВремя сортировкой вставкой: " << differenceArrayC.count() << " микросекунд.";





	int tempD=0, min =0; 
	cout << "\n\nМассив D: "; //выбор
	auto startArrayD = high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arrayD[j] < arrayD[min])
				min = j;
		}
		if (i != min)
		{
			tempD = arrayD[i];
			arrayD[i] = arrayD[min];
			arrayD[min] = tempD;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arrayD[i] << ' ';
	}
	auto stopArrayD = high_resolution_clock::now();
	auto differenceArrayD = duration_cast<microseconds>(stopArrayD - startArrayD);
	cout << "\nВремя сортировкой выбором: " << differenceArrayD.count() << " микросекунд.";





	int tempE;
	cout << "\n\nМассив E: "; //быстрая
	auto startArrayE = high_resolution_clock::now();
	qsortRecursive(arrayE, N);
	for (int i = 0; i < N; i++)
	{
		cout << arrayE[i] << ' ';
	}
	auto stopArrayE = high_resolution_clock::now();
	auto differenceArrayE = duration_cast<microseconds>(stopArrayE - startArrayE);
	cout << "\nВремя  быстрой сортировкой: " << differenceArrayE.count() << " микросекунд.\n";




	delete[]array;
	delete[]arrayB;
	delete[]arrayC;
	delete[]arrayD;
	delete[]arrayE;
	return 0;
}

void qsortRecursive(int* arrayE, int N)
{
	int i = 0;
	int j = N - 1;

	int mid = arrayE[N / 2];
	do {
		while (arrayE[i] < mid) {
			i++;
		}

		while (arrayE[j] > mid) {
			j--;
		}
		if (i <= j)
		{
			int tempE = arrayE[i];
			arrayE[i] = arrayE[j];
			arrayE[j] = tempE;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		qsortRecursive(arrayE, j + 1);
	}
	if (i < N) {
		qsortRecursive(&arrayE[i], N - i);
	}


}

