#include <iostream>

using namespace std;

long long dp[10000010];
int main()
{
    int t, m;
    cin >> t >> m;
    while (m--)
    {
        int cost, value;
        scanf("%d%d", &cost, &value);
        for (int i = cost; i <= t; i++) {
            dp[i] = max(dp[i], dp[i - cost] + value);
        }
    }
    cout << dp[t];
    return 0;
}