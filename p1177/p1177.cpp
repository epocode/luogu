#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

int partition(long long list[], int l, int r) {
    int p = r;
    int mid = (l + r) / 2;
    if (list[l] > list[mid]) {
        swap(list[l], list[mid]);
    }
    if (list[l] > list[r]) {
        swap(list[l], list[r]);
    }
    if (list[mid] > list[r]) {
        swap(list[mid], list[r]);
    }
    int i = l - 1;
    for (int j  = l; j < r; j++) {
        if (list[j] <= list[p]) {
            swap(list[++i], list[j]);
        }
    }
    swap(list[++i], list[p]);
    return i;
}



void insertionSort(long long list[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        long long key = list[i];
        int j = i - 1;
        while (j >= l && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

void quickSort(long long list[], int left, int right) {
    while (left < right) {
        const int threshold = 10;
        if (left + threshold <= right) {
            int pivot = partition(list, left, right);
            if (pivot - left < right - pivot) {
                quickSort(list, left, pivot - 1);
                left = pivot + 1;
            } else {
                quickSort(list, pivot + 1, right);
                right = pivot - 1;
            }
        } else {
            insertionSort(list, left, right);
            break;
        }
    }
}
int main() {
    srand((unsigned int)time(NULL));
    long long N;
    cin >> N;
    long long list[(int)1e6];
    int len = N;
    int i = 0;
    while (N--) {
        long long input;
        cin >> input;
        list[i++] = input;
    }
    quickSort(list, 0, len - 1);
    for (int i = 0; i < len; i++) {
        cout << list[i] << " ";
    }
    return 0;
}