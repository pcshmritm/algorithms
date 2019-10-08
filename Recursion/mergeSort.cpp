#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void merge(int *a, int start, int end) {
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;
    int k = start;

    int temp[end + 1];

    // Compare and merge the two arrays
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // if i hasn't reached to mid then put all the elements in temp array
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    // if j hasn't reached to end then put all the elements in temp array
    while (j <= end) {
        temp[k] = a[j];
        k++;
        j++;
    }

    // copy all the sorted elements from temp to original array
    for (int i = start; i <= end; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(int *a, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;

    // Recursively sort first half of array
    mergeSort(a, start, mid);

    // Recursively sort second half of array
    mergeSort(a, mid + 1, end);

    // Merge the two sorted arrays
    merge(a, start, end);
}

int main() {
    int a[100];
    int n;

    // Take array size as input
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    cout << endl;
}
