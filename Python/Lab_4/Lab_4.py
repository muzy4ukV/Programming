
n = int(input("Enter n: "))
a = float(input("Enter a: "))
b = float(input("Enter b: "))
ri = 0
h = (b - a) / n

if a == b:
    print("Incorrectly entered data")
    quit(0)

for i in range (1, n + 1):
    ri = a + i*h
    print(ri, end = " ")
print()