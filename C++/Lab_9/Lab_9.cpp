#include <string>
#include <iostream>

using namespace std;
bool palindrome(string);
int function(string);

int main()
{
	string myString;
	cout << "Enter your sentence" << endl;
	getline(cin, myString);
	// введення рядка

	int numOfPalindromes = function(myString);
	cout << "Total number of palindromes: " << numOfPalindromes;
	// виведення результату
}

int function(string myString)
{
	int gap = myString.find(" ", 0);
	int number = 0;
	// знаходження позиції першого пробіла
	if (gap == -1 && !(myString.empty()))
		gap = 0;
	// перевірка на випадок, якщо користувач введе тільки одне слово
	while (gap != -1)
	{
		gap = myString.find(" ", 0);
		string word = myString.substr(0, gap);
		// виділення першого слова
		if (palindrome(word)) {
			number += 1;
			myString.erase(0, word.length() + 1);
			// видалення обробленого слова
		}
		else {
			myString.erase(0, word.length() + 1);
		}

	}
	return number;
}

bool palindrome(string word)
// функція для визначення чи є слово паліндромом
{
	string reverseWord;
	for (int i = word.length() - 1; i >= 0; i--)
		reverseWord += word[i];
	// цикл який перевертає слово
	if (word == reverseWord && !(reverseWord.empty()))
	// додаткова перевірка, щоб уникнути сприйняття пробілів як паліндромів
	{
		cout << "Word " << word << " is palindrome\n";
		return true;
	}
	else
		return false;
}