#include <iostream>

using namespace std;
int arr[5000010];
int partition(int left, int right) {
    int mid = (left + right) / 2;
    if (arr[left] > arr[mid]) {
        swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (arr[mid] < arr[right]) {
        swap(arr[mid], arr[right]);
    }
    int p = arr[right];
    int i = left - 1, j = left;
    while (j < right) {
        if (arr[j] <= p) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int p = partition(left, right);
    quickSort(left, p - 1);
    quickSort(p + 1, right);
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = partition(left, right);
        if (mid == k) {
            cout << arr[k];
        }
        if (mid < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}