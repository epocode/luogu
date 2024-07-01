#include <iostream>
#include <algorithm>
using namespace std;

int scoreLine[100010], scores[100010];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> scoreLine[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }
    sort(scoreLine + 1, scoreLine + m + 1);
    sort(scores + 1, scores + n + 1);
    long long  sum = 0;
    for (int i = 1; i <= n; i++) {
        int left = 1, right = m;
        if (scores[i] < scoreLine[left]) {
            sum += abs(scores[i] - scoreLine[left]);
            continue;
        }
        if (scores[i] > scoreLine[right]) {
            sum += abs(scores[i] - scoreLine[right]);
            continue;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (scoreLine[mid] == scores[i]) {
                break;
            } else if (scoreLine[mid] > scores[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left > right) {
            sum += min(abs(scores[i] - scoreLine[left]), abs(scores[i] - scoreLine[right]));
        }
    }
    cout << sum;
    return 0;
}