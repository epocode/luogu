#include <iostream>

using namespace std;
int lcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return lcd(b, a % b);
}

int arr[10010];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++) {
            cin >> arr[i];
        }
        bool flag = false;
        for (int i = 1; i <= t; i++) {
            if (i == 2) {
                continue;
            }
            arr[2] /= lcd(arr[i], arr[2]);
            if (arr[2] == 1) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "No" << endl;
        }
    }
    return 0;
}