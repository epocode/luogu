#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } 
    return gcd(b, a % b);
}
void addFrac(int &a, int &b, int c, int d, char opt) {
    int temp;
    temp = gcd(c, d);
    c /= temp;
    d /= temp;
    temp = gcd(b, d);
    temp = b * d / temp;
    a = temp / b * a;
    c = temp / d * c;
    if (opt == '+') {
        a += c;
    } else {
        a -= c;
    }
    b = temp;
    temp = gcd(a > 0 ? a : -a, b);
    a /= temp;
    b /= temp;
}

int main() {
    int up = 0, down = 1, newUp, newDown;
    string input;
    cin >> input;
    char opt;
    char temp;
    if (input[0] != '-') {
        input = '+' + input;
    }
    for (int i = 0; i < input.length();) {
        opt = input[i++];
        int j = i + 1;
        while (input[j] != '/' && j < input.length()) j++;
        newUp = stoi(input.substr(i, j - i));
        i = j + 1;
        j = i + 1;
        while (input[j] != '+' && input[j] != '-' && j < input.length()) j++;
        newDown = stoi(input.substr(i, j - i));
        i = j;
        addFrac(up, down, newUp, newDown, opt);
    }
    if (up % down == 0) {
        cout << up / down;
    } else {
        cout << up << "/" << down;
    }
    return 0;
}