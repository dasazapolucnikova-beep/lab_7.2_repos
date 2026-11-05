#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int SumMaxInOddColumns(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k row = "; cin >> k;
    cout << "n column = "; cin >> n;

    // Динамічне виділення пам'яті під матрицю k x n
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    int Low = -10, High = 20;

    Create(a, k, n, Low, High);
    cout << "\nInitial matrix:";
    Print(a, k, n);

    int sum = SumMaxInOddColumns(a, k, n);
    cout << "Sum of max elements in odd columns : " << sum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Формування матриці випадковими числами
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці на екран
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Пошук суми максимальних елементів по непарних стовпцях
int SumMaxInOddColumns(int** a, const int rowCount, const int colCount)
{
    int sum = 0;
    // Крок j += 2 перебирає лише непарні стовпці (j = 1, 3, 5...)
    for (int j = 1; j < colCount; j += 2)
    {
        int maxInCol = a[0][j]; // Припускаємо, що перший елемент стовпця є максимальним
        for (int i = 1; i < rowCount; i++)
        {
            if (a[i][j] > maxInCol)
            {
                maxInCol = a[i][j];
            }
        }
        sum += maxInCol;
    }
    return sum;
}

