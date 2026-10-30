#include <iostream>
#include <string>
#include "file_utils.h"

int main() {
    const int MAX_LINES = 100;
    const std::string FILE1 = "file1.txt";
    const std::string FILE2 = "file2.txt";

    // 1. Ввод ФИО
    std::string fullName;
    std::cout << "Введите ФИО: ";
    std::getline(std::cin, fullName);

    // 2. Добавляем ФИО в файл 1 (перезапись)
    WriteNameToFile(FILE1, fullName);
    std::cout << "ФИО записано в " << FILE1 << std::endl;

    // 3. Считываем данные из файла 1 и сохраняем в файл 2 (дописывание)
    std::string lines[MAX_LINES];
    int count = ReadFile(FILE1, lines, MAX_LINES);

    for (int i = 0; i < count; i++) {
        AppendNameToFile(FILE2, lines[i]);
    }
    std::cout << "Данные перенесены из " << FILE1 << " в " << FILE2 << std::endl;

    // 4. Выводим все данные из обоих файлов на экран
    PrintFile(FILE1);
    PrintFile(FILE2);

    std::string str;
    std::cin >> str;

    return 0;
}