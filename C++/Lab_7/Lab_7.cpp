#include <iomanip>
#include <iostream>
#include "stdlib.h"
#include "time.h"
using namespace std;

void arrayInit(double* array, int size);
void arrayOutput(double* array, int size);
int numOfSmaller(double* array, int size, int z);
double maxOfSmall(double* array, int size, int z, int& index);
void change(double* array, int index);


int main()
{
	cout << "Enter a size of array ";
	int size; cin >> size;
	
	cout << "Enter a value of z ";
	int z; cin >> z;

	double* array = new double[size];
	// Введення даних й ініціалізація масиву

	arrayInit(array, size);
	arrayOutput(array, size);
	// Введення виведення масиву

	int number = numOfSmaller(array, size, z);
	printf_s("The number of elemrnts less than %d is %d\n", z, number);
	// Знаходження кількіості елеменів масиву мених за z

	int index = 0;
	double maxElement = maxOfSmall(array, size, z, index);
	printf_s("Max elment is %f and its index is %d\n", maxElement, index);
	// Знаходження знаення та індексу найбільшого елементу серед тих, що менші за z

	change(array, index);
	cout << "New array is: ";
	arrayOutput(array, size);
	// Заміна першого й найбільшого елементів масиву

	delete[] array;
}

void change(double* array, int index)
{
	int k = array[0];
	array[0] = array[index];
	array[index] = k;
}

double maxOfSmall(double* array, int size, int z, int& index)
{
	int k = 0;
	while (array[k] >= z) 
		k++;
	// визначення індексу першого елементу в масиві, який менший за z

	double maxElement = array[k];
	index = k;
	for (; k < size; k++)
		if (array[k] < z && array[k] > maxElement)
		{
			maxElement = array[k];
			index = k;
		}
	// порівняння кожного елемента масиву з метою визначення індексу й значення найбільшого елементу

	return maxElement;
}

int numOfSmaller(double* array, int size, int z)
{
	int number = 0;
	for (int i = 0; i < size; i++)
		if (array[i] < z) number++;
	return number;
	// тут визнаається тільки кількість елементів які менші за задане z
}

void arrayInit(double* array, int size)
{ 
	srand(time(0));
	for (int i = 0; i < size; i++)
		array[i] = static_cast<double>(rand() % 19 - 9.0);
}

void arrayOutput(double* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(3) << array[i] << ' ';
	cout << endl;
}