#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <utility>   // std::swap

int int_input() {
    int input{};
    std::string line;

    while (true) {
        if (!std::getline(std::cin, line)) {
            throw std::runtime_error("EOF");   // или как-то иначе выйти
        }

        std::istringstream iss(line);
        if (iss >> input) {
            iss >> std::ws;                    // пропустить пробелы в конце
            if (iss.eof()) {                   // больше ничего значимого нет
                return input;
            }
        }
        std::cout << "Invalid input\n";       
    }
}

int* input_array(int length) { // Эта функция возвращает указатель на первый элемент массива
    int* array = new int[length];

    for (int i = 0; i < length; i++) {
        std::cout << "Enter " << i+1 << " array element (int): ";
        array[i] = int_input();
    }

    return array;
}

void print_array(const int* array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << (i + 1 < length ? ' ' : '\n');
    }
}

void shuffle(int* array, int length) {
    for (int i = 0; i + 1 < length; i += 2) {
        std::swap(array[i], array[i + 1]);
    }
}

int main() {
    int arrayLength = 6;
    int* array = input_array(arrayLength);

    std::cout << "Original array: ";
    print_array(array, arrayLength);

    shuffle(array, arrayLength);

    std::cout << "Modified array: ";
    print_array(array, arrayLength);

    delete[] array;   // не забыть освободить память
    return 0;

    return 0;
}