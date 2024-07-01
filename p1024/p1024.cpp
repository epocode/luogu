#include <iostream>
#include <cmath>
using namespace std;

int cnt;
double answer[4], a, b, c, d;

double f(double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}
void calcRoot(double low, double high) {
    double l = low;
    while (l < high) {
        double temp = l;
        double r = l + 1;
        if (f(l) == 0) {
            answer[++cnt] = l;
        }
        if (f(l) * f(r) < 0) {
            while (abs(l - r) > 0.001) {
                double mid = (l + r) / 2;
                if (f(mid) == 0) {
                    answer[++cnt] = mid;
                    break;
                }
                if (f(l) * f(mid) < 0) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            answer[++cnt] = l;
        }
        l = temp + 1;

    }
}
int main() {
    cin >> a >> b >> c >> d;
    calcRoot(-100, 100);
    for (int i = 1; i <= cnt; i++) {
        printf("%.2lf ", answer[i]);
    }
    return 0;
}