#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char symbol;

    cout << "Введите строку: ";
    getline(cin, str);

    cout << "Введите символ для поиска: ";
    cin >> symbol;

    int count = 0;
    for (char c : str) {
        if (c == symbol) {
            count++;
        }
    }

    if (count > 0) {
        cout << "Данный символ встречается в строке " << count << " раз" << endl;
    }
    else {
        cout << "Строка не содержит символ" << endl;
    }

    return 0;
}