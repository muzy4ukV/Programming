accuracy = float(input("Введіть точність обчисленння: "))
e = 0
i = 0
fact = 1
current = 1 / fact  
while current > accuracy:
        e = e + current
        i = i + 1
        fact = fact * i
        current = 1 / fact
    
print("e =", e)
