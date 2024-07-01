#include <iostream>

using namespace std;

int main() {
    int w, pay, t;
    cin >> w >> pay >> t;
    double l = 0, r = 3;
    while (r - l > 0.0001) {
        double mid = (l + r) / 2;
        double left = w;
        for (int i = 1; i <= t; i++) {
            left = left * (1 + mid) - pay;
        }
        if (left == 0) {
            l = mid;
            break;
        }
        if (left < 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.1lf", l  * 100);
    return 0;
}

