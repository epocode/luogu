#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace  std;

int main() {
    int n;
    cin >> n;
    vector<int> list;
    vector<int> preSum;
    int input;
    while (n--) {
        cin >> input;
        list.push_back(input);
    }
    preSum.push_back(list[0]);
    for (int i = 1; i < list.size(); ++i) {
        preSum.push_back(preSum[i - 1] + list[i]);
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << preSum[r] - preSum[l] + list[l] << endl;
    }
    return 0;
}