// Первый вариант задания

#include <iostream>;
#include <cmath>;
#include <clocale>;

enum Choice
{
	End,
	Continue
};

float calc(int num) {
	return -std::sin(num - 5);
}

int main1() {
	setlocale(LC_ALL, ""); // Русский язык в терминале

	int x1, userChoice;
	float f1;
	Choice finalChoice;

	while (true) {
		std::cout << "Enter the number: ";
		std::cin >> x1;

		f1 = calc(x1);
		std::cout << "Function output: " << f1 << "\n";

		while (true) {
			std::cout << "Continue?\n1 - Yes\n0 - No\n";
			std::cin >> userChoice;

			if (userChoice == 0) { 
				finalChoice = End;
				break; 
			}
			else if (userChoice == 1) { 
				finalChoice = Continue; 
				break;
			}
			else { 
				std::cout << "Invalid input\n"; 
			}
		}
		if (finalChoice == End) {
			break;
		}
	}
	return 0;
}