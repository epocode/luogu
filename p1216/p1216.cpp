#include <iostream>

using namespace std;
int dp[1010][1010];
int main() {
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            int input;
            cin >> input;
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + input;
        }
    }
    int res = -1;
    for (int j = 1; j <= r; j++) {
        if (dp[r][j] > res) {
            res = dp[r][j];
        }
    }
    cout << res;
    return 0;
}