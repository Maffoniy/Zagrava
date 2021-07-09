// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
double Buble_time(int *arr, int l) {
	clock_t t0 = clock();
	for (int i = 0; i < l - 1; i++)

		// Last i elements are already in place
		for (int j = 0; j < l - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	clock_t t1 = clock();
	return (double)(t1 - t0) / CLOCKS_PER_SEC;
}
double Choice_time(int* arr, int l) {
	clock_t t0 = clock();
	int  k, x;
	for (int i = 0; i < l - 1; i++) /* зовнішній цикл */
	{
		k = i; /* ініціалізовуємо kter в позицію iter */
		x = arr[i]; /* і зберігаємо значення елементу
						   ** оскільки ми повинні ініціалізувати ці значення */

		for (int j = i + 1; j < l; j++) /* внурішній цикл */
		{
			if (arr[j] < x) /* перевіряємо, чи значення елементу менше */
			{/* якщо так, */
				k = j; /* зберігаємо індекс найменшого елементу */
				x = arr[k]; /* зберігаємо його значення */
			}
		}

		/* обмінюємо значення найменшоо елементу масиву з поточним */
		/* поточний елемент (з позиції зовнішнього циклу)
		** в позицію найменшого */
		arr[k] = arr[i];
		/* найменший елемент в позицію поточного */
		arr[i] = x;
	}
	clock_t t1 = clock();
	return (double)(t1 - t0) / CLOCKS_PER_SEC;
	// сортування масиву 10^6 зайняло 1032.05 секунд на 2.9GHz процесорі i5-10400
}
double Insert_time(int* arr, int l) {
	clock_t t0 = clock();
	for (int i = 1; i < l; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
			swap(arr[j - 1], arr[j]);        // меняем местами элементы j и j-1
	clock_t t1 = clock();
	return (double)(t1 - t0) / CLOCKS_PER_SEC;
}



int main()
{
	const int NumZero = 6;
	int Iter = 0;
	double Buble_time_result[NumZero];
	double Choice_time_result[NumZero];
	double Insert_time_result[NumZero];
	random_device rd;
	int N = pow(10, NumZero);
	while(N<=pow(10, NumZero))
	{
		int* local_Darr = new int[N];
		int* local_arrBub = new int[N];
		int* local_arrChoi = new int[N];
		int* local_arrIns = new int[N];
		for (int i = 0; i < N; i++) {
			int rand = rd() % 100 + 1;
			local_arrChoi[i] = rand;
			local_arrIns[i] = rand;
			local_arrBub[i] = rand;
			local_Darr[i] = rand;
		}

		Buble_time_result[Iter]=Buble_time(local_arrBub, N);
		Choice_time_result[Iter]=Choice_time(local_arrChoi, N);
		Insert_time_result[Iter++]=Insert_time(local_arrIns, N);

		delete[] local_Darr;
		delete[] local_arrBub;
		delete[] local_arrChoi;
		delete[] local_arrIns;
		N *= 10;
	}

	cout << flush;

	cout << "Size\t|Buble\t|Choice\t|In\t" << endl;

	for (int i = 0; i < NumZero; i++) {
		cout << pow(10, i + 1) << "\t|" << Buble_time_result[i] << "\t|" << Choice_time_result[i] << "\t |" << Insert_time_result[i] << "\t" << endl;
	}
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
