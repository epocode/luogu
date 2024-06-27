#include <iostream>
#include <math.h>
using namespace std;
long long gcd(long  long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    long long x, y;
    cin >> x >> y;
    long long res = 0;
    long long mul = (long long)x * y;
    for (int p = 2; p <= sqrt(mul); p++) {
        if (mul % p == 0) {
            long long q = mul / p;
            if (gcd(p, q) == x) {
                res += p != q ? 2 : 1;
            } 
        }
    }
    cout << res;
    return 0;
}