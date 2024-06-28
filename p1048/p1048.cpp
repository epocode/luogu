#include <iostream>

using namespace std;

int dp[110][1010];
int main() {
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        int cost, value;
        cin >> cost >> value;
        if (i == 1) {
            for (int j = 0; j <= T; j++) {
                if (j < cost) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = value;
                }
            }
        } else {
            for (int j = 1; j <= T; j++) {
                if (j < cost) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - cost] + value, dp[i - 1][j]);
                }
            }
        }
    }
    int max = -1;
    for (int i = 1; i <= T; i++) {
        if (dp[M][i] > max) {
            max = dp[M][i];
        }
    }
    cout << max;
    return 0;
}