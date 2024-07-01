#include <iostream>

using namespace std;
bool arr[1010];
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int input;
        scanf("%d", &input);
        if (!arr[input]) {
            count++;
        }
        arr[input] = true;
    }
    cout << count << endl;
    for (int i = 0; i < 1010; i++) {
        if (arr[i]) {
            cout << i << " ";
        }
    }
}