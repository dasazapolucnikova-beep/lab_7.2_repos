#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Реалізація функції для тестування без зовнішнього файлу
int SumMaxInOddColumns(int** a, const int rowCount, const int colCount)
{
	int sum = 0;
	for (int j = 1; j < colCount; j += 2)
	{
		int maxInCol = a[0][j];
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

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// 1. Вхідні дані: створення тестової матриці 3х4
			const int k = 3;
			const int n = 4;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			// Заповнення тестовими даними
			a[0][0] = 1;  a[0][1] = 10; a[0][2] = 5; a[0][3] = 3;
			a[1][0] = 2;  a[1][1] = 4;  a[1][2] = 8; a[1][3] = 12;
			a[2][0] = 0;  a[2][1] = -2; a[2][2] = 7; a[2][3] = 9;

			// 2. Виклик функції
			int actual = SumMaxInOddColumns(a, k, n);
			int expected = 22; // max(10, 4, -2) + max(3, 12, 9) = 10 + 12 = 22

			// 3. Перевірка
			Assert::AreEqual(expected, actual);

			// 4. Очищення пам'яті
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}