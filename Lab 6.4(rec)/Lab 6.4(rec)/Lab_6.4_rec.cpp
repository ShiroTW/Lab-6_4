#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void PrintArray(double* a, const int numberOfElements, int i);
double SumOfPositiveElements(double* a, const int size, int i);
double GetProductBetweenMaxAndMinMod(double* a, const int size, int i, double& max, double& min);
void EnterArray(double* a, int size, int i);
void MoveOddElements(double* a, int size, int i);

int main()
{
    setlocale(LC_CTYPE, "ukr");
    const int n = 10;
    double* a = new double[n];

    cout << "Введiть елементи масиву: " << endl;
    EnterArray(a, n, 0);
    cout << endl;

    double positiveSum = SumOfPositiveElements(a, n, 0);
    cout << "Сума додатних елементiв масиву: " << positiveSum << endl;

    double max = a[0], min = a[0];
    double product = GetProductBetweenMaxAndMinMod(a, n, 0, max, min);
    cout << "Добуток елементiв мiж максимальним та мiнiмальним за модулем:" << product << endl;

    MoveOddElements(a, n, 0);
    cout << "Масив пiсля перемiщення непарних елементiв за спаданням: ";
    PrintArray(a, n, 0);

    delete[] a;
    return 0;
}

void PrintArray(double* a, const int numberOfElements, int i)
{
    cout << "a[" << i << "] = " << a[i] << "; ";
    if (i < numberOfElements - 1) {
        PrintArray(a, numberOfElements, i + 1);
    }
    else {
        cout << endl;
    }
}

double SumOfPositiveElements(double* a, const int size, int i)
{
    if (i >= size) return 0;
    if (a[i] > 0) {
        return a[i] + SumOfPositiveElements(a, size, i + 1);
    }
    return SumOfPositiveElements(a, size, i + 1);
}

double GetProductBetweenMaxAndMinMod(double* a, const int size, int i, double& max, double& min)
{
    if (i >= size) return 1;

    if (fabs(a[i]) > fabs(max)) {
        max = a[i];
    }
    if (fabs(a[i]) < fabs(min)) {
        min = a[i];
    }

    return GetProductBetweenMaxAndMinMod(a, size, i + 1, max, min);
}

void EnterArray(double* a, int size, int i)
{
    if (i < size) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        EnterArray(a, size, i + 1);
    }
}

void MoveOddElements(double* a, int size, int i)
{
    if (i >= size) return;

    // Перевіряємо, чи є непарний елемент
    if (static_cast<int>(a[i]) % 2 != 0) {
        double oddValue = a[i];

        // Переміщаємо непарні елементи в кінець масиву за спаданням
        for (int j = i; j < size - 1; ++j) {
            a[j] = a[j + 1];
        }
        a[size - 1] = oddValue;
    }

    MoveOddElements(a, size, i + 1);
}