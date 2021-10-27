#include <iostream>
using namespace std;

int reverse(int x) {
    int y = 0;
    while (x > 0) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

int main()
{
    for (long i = 1000000; i <= 1000000000; i++) {
        long currentNumber = reverse(i);
        if (i == currentNumber) {
            cout << currentNumber << endl;
        }
    }
    return 0;
}