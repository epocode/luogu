#include <iostream>

using namespace std;
int arr[10010];

int bubbleSort(int left, int right) {
    int count = 0;
    for (int i = left; i < right - 1; i++) {
        for (int j = right - 1; j > left; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << bubbleSort(1, n + 1);
    return 0;
}