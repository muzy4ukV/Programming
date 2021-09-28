from math import sqrt

dist_1 = 0 # вводимо змінні
dist_2 = 0
dist_3 = 0
perimeter = 0
area = 0

def get_point(a):                               # функція для перетворення елементів списку в формат float
    return list(map(lambda x: float(x), b))

frst = get_point(input("Введіть  координати першої вершини через пробіл:")) # Введення даних з консолі
scnd = get_point(input("Введіть  координати другої вершини через пробіл:"))
thrd = get_point(input("Введіть  координати третьої вершини через пробіл:"))

dist_1 = sqrt((frst[0] - frst[1]) ** 2 + (scnd[0] - scnd[1]) ** 2) # обчислення дивжин сторін трикутника
dist_2 = sqrt((scnd[0] - scnd[1]) ** 2 + (thrd[0] - thrd[1]) ** 2)
dist_3 = sqrt((thrd[0] - thrd[1]) ** 2 + (frst[0] - frst[1]) ** 2)

def get_perimeter(a, b, c): # функція для знаходження периметру
    perimeter = a + b + c
    return perimeter

def get_area(a, b, c): # функція для знаходження площі
    per = get_perimeter(a, b, c)
    triangle_area = sqrt((per/2) * (per/2 - a) * (per/2 - b) * (per/2 - c))
    return triangle_area

perimeter = get_perimeter(dist_1, dist_2, dist_3) # обчислення периметру і площі
area = get_area(dist_1, dist_2, dist_3)

print("Периметр:", perimeter," ", "Площа:", area) # виведення значень в консоль

