#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int n = N;
    unordered_set<int> rows;
    unordered_set<int> cols;
    int rowCount = 0;
    int colCount = 0;
    while (K--) {
        int row;
        int col;
        scanf("%d%d", &row, &col);
        if (rows.find(row) == rows.end()) {
            rowCount++;
            rows.insert(row);
        }
        if (cols.find(col) == cols.end()) {
            colCount++;
            cols.insert(col);
        }
    }
    long long res;
    res = (long long)rowCount * n + (long long)colCount * n - (long long)colCount * rowCount;
    cout << res;
    return 0;
}