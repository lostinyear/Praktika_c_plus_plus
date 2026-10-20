#include <iostream>

// Создается копия x, оригинал не меняется 
void decrement(int x) {
    --x;
}

// Меняется оригинал
void decrement(int* x) {
    --(*x);
}

int main() {
    int a = 10;
    std::cout << "Before: a = " << a << '\n';

    decrement(a);

    std::cout << "After  decrement(a): a = " << a << "   (изменилось)\n";

    decrement(&a);

    std::cout << "After  decrement(&a): a = " << a << "   (изменилось)\n";

    return 0;
}