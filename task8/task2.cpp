#include <iostream>
#include <fstream>
#include <string>
#include <sstream>   // <-- нужен для stringstream
using namespace std;

int main() {
    // --- Шаг 1: вводим число и сохраняем в primer1.txt ---
    double number;
    cout << "Введите число: ";
    cin >> number;

    ofstream f1("primer1.txt"); // Запись
    f1 << number << endl;
    f1.close();
    cout << "Число сохранено в primer1.txt" << endl;

    // --- Шаг 2: считываем число и вычисляем 50% ---
    ifstream f2("primer1.txt");
    double readNumber = 0;
    f2 >> readNumber;
    f2.close();

    double half = readNumber * 0.5;
    ofstream f3("primer2.txt");
    f3 << half << endl;
    f3.close();
    cout << "50% от числа = " << half << " (сохранено в primer2.txt)" << endl;

    // --- Шаг 3: пытаемся добавить строку в primer1.txt ---
    ofstream f4("primer1.txt", ios::app);  // режим добавления
    f4 << "Это строка, а не число" << endl;
    f4.close();
    cout << "Строка добавлена в primer1.txt" << endl;

    // --- Шаг 4: проверяем, все ли строки файла — числа ---
    ifstream f5("primer1.txt"); // чтение
    string line;
    bool isNumber = true;

    while (getline(f5, line)) {
        stringstream ss(line);
        double test;
        if (!(ss >> test)) {   // не удалось прочитать число
            isNumber = false;
            break;
        }
    }
    f5.close();

    if (!isNumber) {
        cout << "В файле строка. Необходимо число" << endl;
    } else {
        cout << "В файле число" << endl;
    }

    return 0;
}