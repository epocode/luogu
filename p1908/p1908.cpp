#include <iostream>
#include <vector>
using namespace std;

long long res = 0;
int merge(int list[], int left, int mid, int right) {
    int j = mid + 1;
    int i = left;
    while (j <= right && i <= mid) {
        if (list[i] > list[j]) {
            res +=  mid - i + 1;
            j++;
        } else {
            i++;
        }
    }
    //执行正常的归并
    i = left;
    j = mid + 1;
    int k  = 0;
    vector<int> tempList(right - left + 1);
    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            tempList[k++] = list[i++];
        } else {
            tempList[k++] = list[j++];
        }
    }
    while (i <= mid) {
        tempList[k++] = list[i++];
    }
    while (j <= right) {
         tempList[k++] = list[j++];
    }
    for (int i = left; i <= right ; i++) {
        list[i] = tempList[i - left];
    }
}

void mergeSort(int list[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    int list[500010];
    for (int i = 0; i < n; i++)  {
        // int input;
        // cin >> input;   
        // list[i] = input;
        cin >> list[i];
    }
    // mergeSort(list, 0, n - 1);通过
    cout << res << endl;

    return 0;
}