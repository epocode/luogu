#include <iostream>

using namespace std;

long long dp[10010];

int main() {   
    dp[0] = 1;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int price;
        cin >> price;
        for (int j = M; j >= 0; j--) {
            if (j >= price) {
                dp[j] = dp[j] + dp[j - price];
            }
        }
    }
    cout << dp[M];
}