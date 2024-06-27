#include <iostream>
#include <vector>
using namespace std;

char numToCh(int num) {
    return char(num  < 10 ? '0' + num : 'A' + num - 10);
}

int main() {
    vector<char> list;
    int n, R;
    cin >> n >> R;
    int temp = n;
    while (temp) {
        int remaitempder = temp % R;
        if (remaitempder < 0) {
            remaitempder -= R;
            temp = temp / R + 1;
        } else {
            temp /= R;
        }
        list.push_back(numToCh(remaitempder));
    }
    cout << n << "=";
    for (int i = list.size() - 1; i >= 0; --i) {
        cout << list[i];
    }
    cout << "(base" << R << ")";
    return 0;
}