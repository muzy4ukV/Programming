def reverse (x):
    y = 0
    while x > 0:
        y = (y * 10) + (x % 10)
        x = x // 10
    return y

minPalindrom = 1000000
maxPalindrom = 1000000000
invertNumber = 0

for i in range (minPalindrom, maxPalindrom + 1):
    currentNumber = i
    invertNumber = reverse(currentNumber)
    if (currentNumber == invertNumber):
        print(invertNumber)
