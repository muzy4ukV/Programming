accuracy = float(input("Введіть точність обчисленння: "))
e = 1
i = 1
fact = 1
difference = i / fact

while difference > accuracy:
    e = e + (1 / fact)
    i += 1
    fact = fact * i
    difference = i / fact
    
print(e)
