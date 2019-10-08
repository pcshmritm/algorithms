// Program to reverse the digits of a number

#include <math.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int reverseNumber(int number, int length) {
    if (number == 0) return 0;

    int digit = number % 10;
    digit *= pow(10, length - 1);

    return digit + reverseNumber(number / 10, length - 1);
}

int main() {
    int number;
    cin >> number;

    int length = 0;
    int temp = number;
    while (temp > 0) {
        length++;
        temp /= 10;
    }

    cout << reverseNumber(number, length) << endl;
}

