#include <iostream>

using namespace std;
int dp[1010][1010];
int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int lose, win, cost;
        cin >> lose >> win >> cost;
        if (i == 1)
        {
            for (int j = 0; j <= x; j++)
            {
                if (j < cost)
                {
                    dp[i][j] = lose;
                }
                else
                {
                    dp[i][j] = win;
                }
            }
        }
        else
        {
            for (int j = 0; j <= x; j++)
            {
                if (j < cost)
                {
                    dp[i][j] = dp[i - 1][j]  + lose;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j - cost] + win, dp[i - 1][j] + lose);
                }
            }
        }
    }
    int max = -1;
    for (int i = 0; i <= x; i++)
    {
        if (dp[n][i] > max)
        {
            max = dp[n][i];
        }
    }
    cout << 5 * (unsigned int)max;
    return 0;
}