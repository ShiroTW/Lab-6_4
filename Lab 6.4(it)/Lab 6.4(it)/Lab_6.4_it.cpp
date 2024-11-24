#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void PrintArray(double* a, const int numberOfElements);
double SumOfPositiveElements(double* a, const int size);
double GetProductBetweenMaxAndMinMod(double* a, const int size);
void EnterArray(double* a, int size);
void MoveOddElements(double* a, int size);

int main()
{
    setlocale(LC_CTYPE, "ukr");
    const int n = 10;
    double* a = new double[n];

    cout << "Введiть елементи масиву: " << endl;
    EnterArray(a, n);
    cout << endl;

    double positiveSum = SumOfPositiveElements(a, n);
    cout << "Сума додатних елементiв масиву: " << positiveSum << endl;

    double max = a[0], min = a[0];
    double product = GetProductBetweenMaxAndMinMod(a, n);
    cout << "Добуток елементiв мiж максимальним та мiнiмальним за модулем:" << product << endl;

    MoveOddElements(a, n);
    cout << "Масив пiсля перемiщення непарних елементiв за спаданням: ";
    PrintArray(a, n);

    delete[] a;
    return 0;
}


void PrintArray(double* a, const int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++) {
        cout << "a[" << i << "] = " << a[i] << "; ";
    }
    cout << endl;
}

double SumOfPositiveElements(double* a, const int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    return sum;
}

double GetProductBetweenMaxAndMinMod(double* a, const int size)
{
    if (size < 2) return 0;

    double maxMod = fabs(a[0]);
    double minMod = fabs(a[0]);
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 0; i < size; i++) {
        if (fabs(a[i]) > maxMod) {
            maxMod = fabs(a[i]);
            maxIndex = i;
        }
        if (fabs(a[i]) < minMod) {
            minMod = fabs(a[i]);
            minIndex = i;
        }
    }

    int start = min(minIndex, maxIndex) + 1;
    int end = max(minIndex, maxIndex) - 1;

    double product = 1;
    if (start <= end) {
        for (int i = start; i <= end; i++) {
            product *= a[i];
        }
    }
    else {
        product = 0;
    }
    return product;
}

void EnterArray(double* a, int size)
{
    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void MoveOddElements(double* a, int size)
{
    double* odd = new double[size];
    double* even = new double[size];
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < size; i++) {
        if (static_cast<int>(a[i]) % 2 != 0) {
            odd[oddCount++] = a[i];
        }
        else {
            even[evenCount++] = a[i];
        }
    }

    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odd[i] < odd[j]) {
                swap(odd[i], odd[j]);
            }
        }
    }

    for (int i = 0; i < oddCount; i++) {
        a[i] = odd[i];
    }
    for (int i = 0; i < evenCount; i++) {
        a[oddCount + i] = even[i];
    }

    delete[] odd;
    delete[] even;
}
