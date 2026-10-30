#include <iostream>
#include <string>
using namespace std;

// ==================== ЗАДАНИЕ 1 и 2 ====================
class Account {
private:
    string name;       // Название счета
    double balance;    // Сальдо
    double expense;    // Расход
    double income;     // Доход
    double remainder;  // Остаток

    // Статическое поле — общее для всех счетов
    static double totalMoneyInCash;

public:
    // Конструктор принимает только сальдо
    Account(double initialBalance) {
        name = "Account";
        balance = initialBalance;
        expense = 0;
        income = 0;
        remainder = initialBalance;
        totalMoneyInCash += initialBalance;  // добавляем в общую кассу
    }

    // Расход: увеличивает расход и уменьшает общую кассу
    void AddExpense(double amount) {
        expense += amount;
        remainder -= amount;
        totalMoneyInCash -= amount;
    }

    // Доход: увеличивает доход и общую кассу
    void AddIncome(double amount) {
        income += amount;
        remainder += amount;
        totalMoneyInCash += amount;
    }

    // Статическая функция (задание 2)
    static string Greeting() {
        return "Our Bank welcomes you";
    }

    // Для проверки — вывод состояния счета
    void Print() {
        cout << "Account: " << name << endl;
        cout << "  Balance:   " << balance << endl;
        cout << "  Expense:   " << expense << endl;
        cout << "  Income:    " << income << endl;
        cout << "  Remainder: " << remainder << endl;
    }

    static double GetTotalMoney() { return totalMoneyInCash; }
};

// Определение статического поля вне класса
double Account::totalMoneyInCash = 0;


// ==================== ЗАДАНИЕ 3 ====================
class Bank {
protected:
    double bankPercent;  // Процент банка

public:
    Bank(double bp) {
        bankPercent = bp;
    }

    // Виртуальный метод
    virtual void GetPercent(double sum) {
        double result = sum * bankPercent / 100.0;
        cout << "Your bank percent is: " << result << endl;
    }

    virtual ~Bank() {}
};

class MicroBank : public Bank {
private:
    double microPercent;  // Процент микробанка

public:
    // Конструктор принимает два значения
    MicroBank(double mp, double bp) : Bank(bp) {
        microPercent = mp;
    }

    // Переопределяем метод
    void GetPercent(double sum) override {
        double result = sum * (microPercent + bankPercent) / 100.0;
        cout << "Your micro bank percent is: " << result << endl;
    }
};


// ==================== main ====================
int main() {
    // --- Задания 1 и 2 ---
    cout << Account::Greeting() << endl << endl;

    Account account(1000);
    account.AddIncome(500);
    account.AddExpense(200);
    account.Print();
    cout << "Total money in cash: " << Account::GetTotalMoney() << endl << endl;

    // --- Задание 3 ---
    Bank bank(10);
    MicroBank microBank(5, 10);

    // Полиморфизм через указатель на базовый класс
    Bank* pointer1 = &bank;
    Bank* pointer2 = &microBank;

    pointer1->GetPercent(1000);  // 10% от 1000 = 100
    pointer2->GetPercent(1000);  // (5+10)% от 1000 = 150

    return 0;
}