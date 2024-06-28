#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};
int hinder[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
long long dp[100][100];
int main() {
    Point horse;
    Point b;
    cin >> b.x >> b.y >> horse.x >> horse.y;
    for (int i = 0; i < 8; i++) {
        Point temp{horse.x + hinder[i][0], horse.y + hinder[i][1]};
        if (temp.x >= 0 && temp.x <= b.x && temp.y >= 0 && temp.y <= b.y) {
            dp[temp.x][temp.y] = -1;
        }
    }
    dp[horse.x][horse.y] = -1;
    dp[0][0] = 1;
    for (int i = 1; i <= b.x; i++) {
        if (dp[i][0] == -1) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int j = 1; j <= b.y; j++) {
        if (dp[0][j] == -1) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i <= b.x; i++) {
        for (int j = 1; j <= b.y; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    cout << dp[b.x][b.y];
    return 0;
}