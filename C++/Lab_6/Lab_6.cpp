#include <iostream>
#include <math.h>

using namespace std;

double a, b, accuracy;  // Початкові значення

void init();                                // Функція для введення поаткових значень а, b та точності
double calculate(double, double, double);   // Функція для обрахування значення виразу із заданою тоністю
void result(double finish);                 // Виведення результату
double t_cos(float, int);                   // Функція яка рахує косинус за допомогою формули Тейлора із заданою k кількістю членів послідовності
int fact(int);                              // Факторіал

int main() {

	init();
	long double res = calculate(a, b, accuracy);
	result(res);  // Виведення результату
	return 0;
}

void init()  // Функція для введення поаткових значень а, b та точності
{
	cout << "Enter a value of a, b: "; cin >> a >> b;
	cout << "Enter an accuracy: "; cin >> accuracy;
}

double calculate(double a, double b, double accuracy)  // Функція для обрахування значення виразу із заданою тоністю
{
	long double current = 0;       // Поточне значення виразу
	long double previous, differ;  // Попереднє значення виразу та одуль різниці між поточним і попереднім значенням виразу
	int k = 1;                     // Змінна яка задає кількість членів послідовності із ряду Тейлора для обрахування заданої точності
	do
	{
		previous = current;
		current = t_cos(a, k) + pow(t_cos(b, k), 2) + t_cos(a + b, k);
		differ = fabs(current - fabs(previous));
		printf_s(" %d) Current difference: %.10f; Current value: %f and previous value %f;\n\n", k, differ, current, previous);
		k++;
	} while (accuracy <= differ);   // Цикл який перевіряє умову точності
	return previous;
}

void result(double finish) 
{
	printf_s(" cos(%1.2f) + cos(%1.2f)^2 + cos(%1.2f) = %.10f\n", a, b, a + b, finish);
}

double t_cos(float x, int k)  // Функція яка рахує косинус за допомогою формули Тейлора із заданою k кількістю членів послідовності
{
	long double sum = 1;
	for (int i = 1; i <= k; ++i) {
		sum += pow(-1, i) * (pow(x, 2 * i)) / fact(2 * i);
	}
	return sum;
}

int fact(int n)  // Розрахунок факторіалу ітераційним способом
{
	long sum = 1;
	while (n > 0)
	{
		sum *= n;
		n--;
	}
	return sum;
}