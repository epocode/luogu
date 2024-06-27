#include <iostream>

using namespace std;

int main() {
    unsigned int num;
    cin >> num;
    unsigned int temp = num;
    unsigned int upper = temp << 16;
    unsigned int lower = temp >> 16;
    cout << upper + lower;
    return 0;
}