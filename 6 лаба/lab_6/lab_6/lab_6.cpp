#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <chrono>
#define INT_MAX 32767


using namespace std;

class hashTable {
public:
	struct hashNode {
		int phone{};
		string name{};

		hashNode(int ph, string* nm)
			: phone{ ph }, name{ *nm }
		{}

	private:
		hashNode* next{};
		friend hashTable;
	};
private:
	size_t m_length{};
	vector<hashNode*> m_data{};

	int hashIndex(int phone) {
		phone = ((phone >> 16) ^ phone) * 0x45d9f3b;
		phone = ((phone >> 16) ^ phone) * 0x45d9f3b;
		phone = (phone >> 16) ^ phone;
		return phone % m_length;
	}

public:
	hashTable(size_t length) : m_length{ length } {
		m_data.resize(length); //создание экземпляра хеш-таблицы
	}

	void resize(size_t length) {
		m_length = length; // Установка длины хэш-таблицы
		m_data.resize(length); // Изменение размера вектора хэш-таблицы
	}

	void addhash(int phone, string name) {
		int id = hashIndex(phone); // Вычисление индекса хэша
		hashNode* p = m_data[id]; // Получение указателя на первый элемент списка для данного хэша
		if (!p) { // Если список пуст
			m_data[id] = new hashNode{ phone, &name }; // Создание нового узла с указанным телефонным номером и именем
			return; // Выход из функции
		}

		while (p->next) p = p->next; // Поиск последнего элемента списка
		p->next = new hashNode{ phone, &name }; // Создание нового узла и присоединение его к концу списка

		return; // Выход из функции
	}

	void deletehash(int phone) {
		int id = hashIndex(phone); // Вычисление индекса хэша для заданного телефонного номера
		auto el = m_data[id]; // Получение указателя на первый элемент списка для данного хэша

		if (el->phone == phone) { // Если первый элемент списка соответствует заданному телефонному номеру
			m_data[id] = el->next; // Удаление первого элемента списка
			delete el; // Освобождение памяти
			return; // Выход из функции
		}

		while (el->next && el->next->phone != phone) el = el->next; // Поиск элемента для удаления
		if (el->next) { // Если элемент для удаления найден
			auto temp{ el->next }; // Сохранение указателя на удаляемый элемент
			el->next = el->next->next; // Удаление элемента из списка
			delete temp; // Освобождение памяти
		}
		cout << "Удалён"; // Вывод сообщения об успешном удалении
	}

	void searchhash(int phone) {
		auto start = chrono::high_resolution_clock::now(); // Запуск таймера

		int id = hashIndex(phone); // Вычисление индекса хэша для заданного телефонного номера
		hashNode* p = m_data[id]; // Получение указателя на первый элемент списка для данного хэша

		while (p && p->phone != phone) // Поиск элемента с заданным телефонным номером
			p = p->next; // Переход к следующему элементу списка
		auto end = chrono::high_resolution_clock::now(); // Остановка таймера
		cout << "Найден: " << p->name << " время: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "нс\n"; // Вывод найденного элемента и времени поиска
	}

	void outputtable() {
		int counter = 0; // Переменная для подсчета элементов
		for (auto el : m_data) { // Цикл по всем элементам хэш-таблицы
			counter++; // Увеличение счетчика элементов
			if (!el) { // Если элемент пустой
				cout << counter << " - " << "Пусто" << '\n'; // Вывод сообщения о пустом элементе
				continue; // Пропуск итерации цикла
			}

			cout << counter << " - " << el->phone << " Имя: " << el->name << '\n'; // Вывод информации о первом элементе списка
			while ((el = el->next)) // Цикл по всем элементам списка
				cout << "<" << el->phone << " Имя: " << el->name << ">\n"; // Вывод информации о последующих элементах
		}
	}

};

int menu() {
	int choice;
	cout << "1. Добавить элемент\n";
	cout << "2. Удалить элемент\n";
	cout << "3. Найти элемент\n";
	cout << "4. Вывести таблицу\n";
	cout << "5. Выйти\n";
	cout << "Выбор: ";
	cin >> choice;
	return choice;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Ввелите размер таблицы \n";
	size_t size;
	cin >> size;
	hashTable table = size;

	for (;;) {
		int phone;
		int choice = menu();

		if (choice < 0 || choice > 5) { cout << "Ошибка"; continue; }

		switch (choice) {
		case 1: {
			int phone;
			cout << "\nНомер: ";
			while (true) {
				cin >> phone;
				if (phone > INT_MAX) {
					cout << "Большое число\n";
					continue;
				}
				break;
			}
			cin.ignore();
			cout << "\nИмя: ";
			string name;
			getline(cin, name);
			table.addhash(phone, name);
			break;
		}
		case 2:
			cin >> phone;
			table.deletehash(phone);
			break;
		case 3:
			cin >> phone;
			table.searchhash(phone);
			break;
		case 4:
			table.outputtable();
			break;
		case 5:
			return 0;
		}
	}
}