#include <string>;
#include <iostream>;

class Car {

public:
	std::string name;
	double speed;

	Car(const std::string& name, double speed)
		: name(name), speed(speed) {}

	bool operator==(const Car& other) const { // const говорит, что мы обещаем не изменять сравниваемый объект, а используя & мы не копируем
		// всю машину в новую область памяти, а берем только указатель на нее
		return name == other.name && speed == other.speed;
	}

	bool operator!=(const Car& other) const {
		return !(*this == other); 
	}

	bool operator<(const Car& other) const {
		return speed < other.speed;
	}

	// > : сравнение по скорости
	bool operator>(const Car& other) const {
		return speed > other.speed;
	}
};




void main() {
	Car a("Car slow", 100);
	Car b("Car fast", 120);

	std::cout << std::boolalpha;
	std::cout << a.name << " == " << b.name << " -> " << (a == b) << "\n";
	std::cout << a.name << " > " << b.name << " -> " << (a > b) << "\n";
	std::cout << a.name << " < " << b.name << " -> " << (a < b) << "\n";
}