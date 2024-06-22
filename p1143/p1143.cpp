#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int chToNum(char ch) {
    if ((int)ch >= '0' && (int)ch <= '9') {
        return int(ch - '0');
    } else {
        return (int)(ch - 'A') + 10;
    }
}

char numToCh(int num) {
    if (num < 10) {
        return (char)('0' + num);
    } else {
        return (char)('A' + num - 10);
    }
}
int main() {
    int from, to;
    string input;
    cin >> from >> input >> to;
    int decNum  = 0;
    for (int i = 0; i < input.length(); ++i) {
        int curNum = chToNum(input[i]);
        decNum = from * decNum + curNum;
    }
    vector<char> chList;
    while (decNum) {
        int remainder = decNum % to;
        chList.push_back(numToCh(remainder));
        decNum /= to;
    }
    for (int i = chList.size() - 1; i >= 0; --i) {
        cout << chList[i];
    }
    return 0;
}