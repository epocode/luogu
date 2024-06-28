#include <iostream>

using namespace std;
int f[1000010];
int s[1000010];
void makeF(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            f[j]++;
        }
        s[i] += f[i] + s[i - 1];
    }
}

int main() {
    int n;
    cin >> n;
    makeF(n);
    cout << s[n];
    return 0;
}