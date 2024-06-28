#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } 
    return gcd(b, a % b);
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long temp = a * b / gcd(a, b);
    temp = temp * c / gcd(temp, c);
    cout << temp;
    return 0;
}