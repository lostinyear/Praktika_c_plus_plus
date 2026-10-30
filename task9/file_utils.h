#pragma once

#include <string>

// Записать ФИО в файл в режиме перезаписи (trunc)
void WriteNameToFile(const std::string& filename, const std::string& name);

// Считать все строки из файла
// Возвращает количество прочитанных строк
int ReadFile(const std::string& filename, std::string lines[], int maxLines);

// Дописать строку в конец файла (app)
void AppendNameToFile(const std::string& filename, const std::string& name);

// Вывести все строки файла на экран
void PrintFile(const std::string& filename);