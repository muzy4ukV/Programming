accuracy = float(input("Введіть точність обчисленння: "))
e = 1
i = 1
fact = 1
previous = 0
current = 1 / (fact)
difference = abs(current - previous)

while difference > accuracy:
    e = e + current
    i += 1
    fact = fact * i
    previous = current
    current = 1 / fact
    difference = abs(current - previous)
    
print(e)
