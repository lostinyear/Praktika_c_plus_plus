#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    char symbol1, symbol2;

    cout << "Введите строку: ";
    getline(cin, str);

    cout << "Введите символ для поиска: ";
    cin >> symbol1;

    cout << "Введите символ для замены: ";
    cin >> symbol2;

    if (str.find(symbol1) != string::npos) {
        replace(str.begin(), str.end(), symbol1, symbol2);
        cout << "Символ заменен" << endl;
        cout << "Результат: " << str << endl;
    }
    else {
        cout << "Символ не найден" << endl;
    }

    return 0;
}