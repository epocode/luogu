#include <iostream>

using namespace std;
int dp[1000000];
int main() {   
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int value ;
        cin >> value;
        dp[i] = max(value, dp[i - 1] + value);
    }
    int max = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max;
    return 0;
}