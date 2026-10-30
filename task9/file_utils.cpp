#include "file_utils.h"
#include <fstream>
#include <iostream>

// Перезаписываем файл: открываем с ios::trunc (по умолчанию для ofstream)
void WriteNameToFile(const std::string& filename, const std::string& name) {
    std::ofstream fout(filename);  // перезапись
    if (!fout.is_open()) {
        std::cerr << "Не удалось открыть " << filename << " для записи" << std::endl;
        return;
    }
    fout << name << '\n';
    fout.close();
}

// Читаем все строки в массив lines, возвращаем количество
int ReadFile(const std::string& filename, std::string lines[], int maxLines) {
    std::ifstream fin(filename); // чтение
    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть " << filename << " для чтения" << std::endl;
        return 0;
    }

    int count = 0;
    std::string line;
    while (std::getline(fin, line) && count < maxLines) { // пока читается строка и пока все не дочитали
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        lines[count++] = line;
    }
    fin.close();
    return count;
}

// Дописываем в конец файла: ios::app
void AppendNameToFile(const std::string& filename, const std::string& name) {
    std::ofstream fout(filename, std::ios::app); // запись
    if (!fout.is_open()) {
        std::cerr << "Не удалось открыть " << filename << " для дописывания" << std::endl;
        return;
    }
    fout << name << '\n';
    fout.close();
}

// Печатаем содержимое файла
void PrintFile(const std::string& filename) {
    std::ifstream fin(filename); // чтение
    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть " << filename << " для чтения" << std::endl;
        return;
    }

    std::cout << "--- Содержимое " << filename << " ---" << std::endl;
    std::string line;
    bool empty = true;
    while (std::getline(fin, line)) { // getline построчно читает строки из файла при вызове 
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        std::cout << line << std::endl;
        empty = false;
    }
    if (empty) std::cout << "(файл пуст)" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    fin.close();
}