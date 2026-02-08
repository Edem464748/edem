#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int number;
    int shift;

    cout << "Введите целое число: ";
    cin >> number;

    cout << "Введите количество позиций для сдвига: ";
    cin >> shift;

    int leftShift = number << shift;   
    int rightShift = number >> shift;  

    cout << "Арифметический сдвиг влево: " << leftShift << endl;
    cout << "Арифметический сдвиг вправо: " << rightShift << endl;

    return 0;
}