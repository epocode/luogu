#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int len;
        cin >> len;
        res ^= len;
    }
    cout << res;
    return 0;
}