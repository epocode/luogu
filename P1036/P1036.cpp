#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPrime(int input) {
    if (input == 1) {
        return false;
    }
    if (input == 2 || input == 3) {
        return true;
    }
    for (int i = 2; i * i <= input; i++) {
        if (input % i == 0) {
            return false;
        }
    }
    return true;
}

int typeNum = 0;
void dfs(int list[], int len, int index, int targetSelectedNum, int selectedNum, int totalSum) {
    if (selectedNum == targetSelectedNum) {
        if (isPrime(totalSum)) {
            typeNum++;
        }
        return;
    }
    for (int i = index; i < len; i++) {
        dfs(list, len, i + 1, targetSelectedNum, selectedNum + 1, totalSum + list[i]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int list[21];
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        list[i] = input;
    }
    dfs(list, n, 0, k, 0, 0);
    cout << typeNum;
    

    return 0;
}