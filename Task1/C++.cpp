#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления значения Y в зависимости от X
double calculateY(double x) {
    if (x < -5) {
        return 2; // Прямая параллельная оси x
    } 
    else if (x >= -5 && x < -1) {
        return -sqrt(4-pow((x+3), 2))+2; // Нижняя часть окружности
    } 
    else if (x >= -1 && x <= 1) {
        return (-3)*pow(x,2)+1; // Парабола для -1 <= x <= 1
    } 
    else if ((x > 1 && x <= 2) || (x >= 4)) {
        return 0; // Прямая параллельная оси x
    }
    else {
        return sqrt(1-pow((x-3),2)); // Верхняя часть окружности
    }
}

int main() {
    double xStart, xEnd, dx;

    // Ввод параметров
    cout << "Введите начальное значение X: ";
    cin >> xStart;
    cout << "Введите конечное значение X: ";
    cin >> xEnd;
    
    // Проверка корректности ввода
    while ((xEnd-xStart) == 0) {
        cout << "Разница между Хнач и Хкон должна быть больше 0." << endl;
        cout << "Введите начальное значение X: ";
        cin >> xStart;
        cout << "Введите конечное значение X: ";
        cin >> xEnd;
    }
    
    cout << "Введите шаг dx: ";
    cin >> dx;

    // Проверка корректности ввода
    while (dx <= 0) {
        cout << "Шаг dx должен быть положительным." << endl;
        cout << "Введите шаг dx: ";
        cin >> dx;
    }

    // Вывод таблицы
    cout << "-----------------" << endl;
    cout << "|   X   |   Y   |" << endl;
    cout << "-----------------" << endl;

    for (double x = xStart; x <= xEnd; x += dx) {
        double y = calculateY(x);
        cout << "| " << setw(6) << fixed << setprecision(2) << x << " | " << setw(6) << fixed << setprecision(2) << y << " |" << endl;
    }

    cout << "-----------------" << endl;

    return 0;
}
