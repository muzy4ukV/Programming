from math import factorial, fabs

def init():  # Функція для введення поаткових значень а, b та точності 
    global a 
    a = float(input("Enter a value of a: "))
    global b
    b = float(input("Enter a value of b: "))
    global accuracy 
    accuracy = float(input("Enter an accuracy: "))

def t_cos(x, k):  # Функція яка рахує косинус за допомогою формули Тейлора із заданою k кількістю членів послідовності
    sum = 1
    for i in range(1, k+1):
        sum += pow(-1, i) * (pow(x, 2 * i)) / factorial(2 * i)
    return sum

def calculate(a, b, accuracy):  # Функція для обрахування значення виразу із заданою тоністю
    k = 1                       # Змінна яка задає кількість членів послідовності із ряду Тейлора для обрахування заданої точності
    previous = 0                # Попереднє значення виразу
    current = t_cos(a, k) + pow(t_cos(b, k), 2) + t_cos(a + b, k)         # Розрахування значення виразу
    differ = fabs(current - fabs(previous))                               # Модуль різниці між поточним і попереднім значенням виразу
    print(" {}) Current difference: {}; Current value: {} and previous value {};\n".format(k, differ, current, previous))

    while accuracy <= differ:   # Цикл який перевіряє умову точності
        previous = current
        k += 1
        current = t_cos(a, k) + pow(t_cos(b, k), 2) + t_cos(a + b, k)
        differ = fabs(current - fabs(previous))
        print(" {}) Current difference: {}; Current value: {} and previous value {};\n".format(k, differ, current, previous))
    return previous

init()
# Задання початкових даних

result = calculate(a, b, accuracy)
# Обрахунок виразу із заданою точністю і параметрами

print(" cos(%1.2f) + cos(%1.2f)^2 + cos(%1.2f) = %.10f\n"%(a, b, a + b, result))
# Виведення результатів



    
