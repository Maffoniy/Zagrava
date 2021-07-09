// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <fstream>
using namespace std::chrono;
using namespace std;
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void Save(string s) {
	ofstream out; 
	out.open("arr.txt", std::ios::app);
	out << s;
	out.close();
	cout << s;
}
void Buble(int* arr, int l) {
	auto start = high_resolution_clock::now();
	unsigned __int64 iterator = 0;
	for (int i = 0; i < l - 1; i++)

		// Last i elements are already in place
		for (int j = 0; j < l - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				iterator++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	string s = "\tBubble sort complited!\nSize: " + to_string(l) + " | Result time: " + to_string(duration.count()) + " | Iterarions: " + to_string(iterator)+"\n";
	Save(s);
	//cout << "\tBubble sort complited!" << endl << "Size: " << l << " | Result time: " << duration.count() << " | Iterarions: " << iterator << endl;
}
void Choice(int* arr, int l) {
	auto start = high_resolution_clock::now();
	unsigned __int64 iterator = 0;
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
				iterator++;
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
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\tSelection sort complited!" << endl << "Size: " << l << " | Result time: " << duration.count() << " | Iterarions: " << iterator << endl;

	string s = "\tSelection sort complited!\nSize: " + to_string(l) + " | Result time: " + to_string(duration.count()) + " | Iterarions: " + to_string(iterator) + "\n";
	Save(s);
}
void Insert(int* arr, int l) {
	auto start = high_resolution_clock::now();
	unsigned __int64 iterator = 0;


	for (int i = 1; i < l; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			iterator++;// пока j>0 и элемент j-1 > j, x-массив int
			swap(arr[j - 1], arr[j]);        // меняем местами элементы j и j-1
		}


	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "\tInsertion sort complited!" << endl << "Size: " << l << " | Result time: " << duration.count() << " | Iterarions: " << iterator << endl;

	string s = "\tInsertion sort complited!\nSize: " + to_string(l) + " | Result time: " + to_string(duration.count()) + " | Iterarions: " + to_string(iterator) + "\n";
	Save(s);
}



int main()
{
	const int NumZero = 7;
	int N = 10;
	int Iter = 0;

	random_device rd;

	while (N <= pow(10, NumZero))
	{
		int* local_Darr = new int[N];
		int* local_arrBub = new int[N];
		int* local_arrChoi = new int[N];
		int* local_arrIns = new int[N];

		for (int i = 0; i < N; i++) {
			int rand = rd() % N + 1;
			local_arrChoi[i] = rand;
			local_arrIns[i] = rand;
			local_arrBub[i] = rand;
			local_Darr[i] = rand;
		}
		
		Buble(local_arrBub, N);
		Choice(local_arrChoi, N);
		Insert(local_arrIns, N);

		cout << "\n\tUnsorted array" << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << local_Darr[i] << " ";
		}
		cout << "\n\tBubble sorted array" << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << local_arrBub[i] << " ";
		}
		cout << "\n\tSelection sorted array" << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << local_arrChoi[i] << " ";
		}
		cout << "\n\tInsertion sorted array" << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << local_arrIns[i] << " ";
		}
		cout << endl << "==============================" << endl;
		delete[] local_Darr;
		delete[] local_arrBub;
		delete[] local_arrChoi;
		delete[] local_arrIns;
		N *= 10;
	}

	system("pause");
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
