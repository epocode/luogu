#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    long long res = 0;
    long long u = max(x, y);
    long long d = min(x, y);
    while (u % d != 0) {
        res += u / d * 4 * d;
        u = u % d;
        y = u;
        x = d;
        u = max(x, y);
        d = min (x, y);
    }
    res += 4 * u;
    cout << res;
    return 0;
}