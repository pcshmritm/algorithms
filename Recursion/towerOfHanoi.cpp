// Solution of Tower Of Hanoi problem

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void towerOfHanoi(int n, char source, char destination, char helper) {
    if (n == 0) return;

    // Move n - 1 disks from source to helper using destination as helper
    towerOfHanoi(n - 1, source, helper, destination);

    // Move nth disk from source to destination
    cout << "Move " << n << " disk from " << source << " to " << destination << endl;

    // Move n - 1 disks from helper to destination using source as helper
    towerOfHanoi(n - 1, helper, destination, source);
}

int main() {
    char source = 'A';
    char helper = 'B';
    char destination = 'C';

    int disks;
    cin >> disks;

    towerOfHanoi(disks, source, destination, helper);
}
