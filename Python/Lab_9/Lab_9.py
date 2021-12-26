def palindrome(word):
    if not word:
        return False
    # додаткова перевірка на пустий рядок
    reversed_word = word[::-1]
    # перевертання слова за допомогою зрізу
    return reversed_word == word

def function(my_string):
    my_string = my_string.split(" ")
    # розділення всіх слів і запис їх у список
    num_of_words = len(my_string)
    number = 0
    for i in range (num_of_words):
    # цикл для перевірки кожного слова
        if palindrome(my_string[i]):
        # перевирка чи є слово паліндромом
            print("Word ", my_string[i], " is palindrome")
            number += 1
    return number

my_string = input("Enter your sentence\n")
# введення рядка
num_of_palindromes = function(my_string)
# визначення кількості паліндромів
print("Total number of palindromes is ", num_of_palindromes)
