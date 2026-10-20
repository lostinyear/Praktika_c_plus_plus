#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];

    cout << "Введите 10 чисел:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Введите число для поиска: ";
    cin >> target;

    int* pos = find(arr, arr + N, target);

    if (pos != arr + N) {
        int index = pos - arr;
        cout << "Число найдено. Индекс: " << index
            << ", позиция: " << index + 1 << endl;
    }
    else {
        cout << "число не найдено" << endl;
    }

    return 0;
}