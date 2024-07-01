#include <iostream>

using namespace std;

bool list[1010];
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Not jolly";
    }
    int pre;
    cin >> pre;
    for (int i = 2; i <= n; i++) {
        int cur;
        cin >> cur;
        int diff = abs(cur - pre);
        if (diff <= n - 1) {
            list[diff] = true;
        }
        pre = cur;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (!list[i]) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}