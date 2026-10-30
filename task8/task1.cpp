#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    const int MAX_WORDS = 40;
    const int MAX_LEN = 80;

    std::ifstream fin("input.txt"); // открываем файл на запись, создаем поток
    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть input.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> words; // массив
    std::string line;

    // Читаем слова построчно
    while (std::getline(fin, line) && words.size() < MAX_WORDS) {
        // Убираем возможные \r (Windows-переводы строк)
        if (!line.empty() && line.back() == '\r') // line.back() читает последний символ строки
            line.pop_back(); // удаляет последний символ

        if (line.empty()) continue;          // пропускаем пустые строки
        if (line.size() > MAX_LEN) {
            std::cerr << "Слово длиннее 80 символов: " << line << std::endl;
            continue;
        }
        words.push_back(line); // добавляет копию строки в конец вектора (массива)
    }
    fin.close();

    // Сортируем по алфавиту
    std::sort(words.begin(), words.end());

    std::ofstream fout("output.txt"); // чтение
    if (!fout.is_open()) {
        std::cerr << "Не удалось открыть output.txt" << std::endl;
        return 1;
    }

    for (const auto& w : words)
        fout << w << '\n';

    fout.close();
    std::cout << "Отсортировано " << words.size() << " слов в output.txt" << std::endl;
    return 0;
}