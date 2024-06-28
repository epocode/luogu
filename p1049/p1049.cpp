#include <iostream>

using namespace std;

int dp[40][20010];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        if (i == 0) {
            for (int j = 0; j <= V; j++) {
                if (j < size) {
                    dp[i][j] = j;
                } else {
                    dp[i][j] = j - size;
                }
            }
        } else {
            for (int j = 0; j <= V; j++) {
                if (j < size) {
                    dp[i][j] = dp[i - 1][j]; 
                } else {
                    dp[i][j] = min(dp[i - 1][j - size], dp[i - 1][j]);
                }
            }
        }
    }
    cout << dp[n - 1][V];
    return 0;
}