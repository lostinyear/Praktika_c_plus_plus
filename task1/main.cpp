#include <iostream>;
#include <cmath>;
#include <clocale>;

int main() {
	setlocale(LC_ALL, ""); // Русский язык в терминале
	
	int x1;
	int x2;
	int max;

	std::cout << "Введите первое число: ";
	std::cin >> x1;

	std::cout << "Введите второе число: ";
	std::cin >> x2;

	if (x1 > x2) { max = x1; }
	else { max = x2; }

	std::cout << "Наибольшее число: " << max << ", вычисляем функцию..\n";

	float f1 = -std::sin(max - 5);
	
	std::cout << "Вывод функции №1: " << f1 << "\n";

	return 0;
}