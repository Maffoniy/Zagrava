﻿// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
using namespace std;
int main()
{
    random_device rd;
    mt19937 mersenne(rd());
    int* arr1 = new int[10];
    int* arr2 = new int[100];
    int* arr3 = new int[1000];
    int* arr4 = new int[10000000];
    for (int i = 0; i < 10; i++) {
        arr1[i] = mersenne() % 100 + 1;
    }
    for (int i = 0; i < 100; i++) {
        arr2[i] = mersenne() % 100 + 1;
    }
    for (int i = 0; i < 1000; i++) {
        arr3[i] = mersenne() % 100 + 1;
    }
    for (int i = 0; i < 10000000; i++) {
        arr4[i] = mersenne() % 100 + 1;
    }
    std::cout << "Hello World!\n";
}
void Buble(int* arr, int l) {
    int x;
    for (int i = 1; i < l; i++) /* зовнішній цикл */
    {
        for (int j = l - 1; j >= i; j--) /* внутрішній цикл */
        {
            if (arr[j] < arr[i - 1]) /* умова перебору */
            {
                /* міняємо місцями значення масиву*/

                /* зберігаємо значення більшого елементу в змінну */
                x = arr[j - 1];
                /* переміщамо менший елемент на одну позицію вліво */
                arr[j - 1] = arr[j];
                /* більший елемент переміщаємо на одну позицію вправо */
                arr[j] = x;
            }
        }
    }
}
void Coice(int* arr, int l) {
   
}
void Pushin(int* arr, int l) {

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
