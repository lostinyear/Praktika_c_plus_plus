#include <iostream>
#include <string>

class Account {
private:
    std::string name;
    double balance;   // остаток
    double expense;   // расход
    double income;    // доход

public:
    Account(const std::string& name, double balance = 0.0,
        double expense = 0.0, double income = 0.0)
        : name(name), balance(balance), expense(expense), income(income) {}

    // Разница между постфиксным и префиксным инкрементами в том, что при использовании значения 
    // постфиксный инкремент/декремент - использует значение ПОСЛЕ инкремента/декремента
    // префиксный инкремент/декремент - - использует значение ДО инкремента/декремента

    // ---- Инкремент: доход += 1 ----
    // Префиксный:  ++acc
    Account& operator++() {
        ++income;
        return *this;
    }

    // Постфиксный: acc++
    Account operator++(int) {
        Account copy = *this;   // снимок "до"
        ++income;
        return copy;            // вернуть "до"
    }

    // ---- Декремент: расход += 1 ----
    // Префиксный:  --acc
    Account& operator--() {
        ++expense;
        return *this;
    }

    // Постфиксный: acc--
    Account operator--(int) {
        Account copy = *this;
        ++expense;
        return copy;
    }

    // ---- Сложение с числом ----
    //  amount > 0 → доход += amount
    //  amount < 0 → расход += -amount  (то есть |amount|)
    Account operator+(double amount) const {
        Account result = *this;
        if (amount > 0) {
            result.income += amount;
        }
        else if (amount < 0) {
            result.expense += -amount;   // минус на минус = плюс
        }
        return result;
    }

    // Симметрия: число + аккаунт
    friend Account operator+(double amount, const Account& acc) {
        return acc + amount;
    }

    // Для наглядного вывода
    friend std::ostream& operator<<(std::ostream& os, const Account& a) {
        os << "Account(name=\"" << a.name << "\""
            << ", balance=" << a.balance
            << ", expense=" << a.expense
            << ", income=" << a.income << ")";
        return os;
    }
};

int main() {
    Account acc("Иван", 1000, 200, 500);
    std::cout << "Исходный:      " << acc << "\n";

    ++acc;                                  // income += 1
    std::cout << "После ++acc:   " << acc << "\n";

    --acc;                                  // expense += 1
    std::cout << "После --acc:   " << acc << "\n";

    Account a2 = acc + 300;                 // income += 300
    std::cout << "acc + 300:     " << a2 << "\n";

    Account a3 = acc + (-150);              // expense += 150
    std::cout << "acc + (-150):  " << a3 << "\n";

    return 0;
}