#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long getHash(string s) {
    long long res = 0;
    long long M = 1e9;
    long long b = 223;
    for (int i = 0; i < s.length(); i++) {
        res = (res * b + s[i]) % M;
    }
    return res;
}

int main() {
    vector<long long> hashList;
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
       long long hash = getHash(str);
       if (find(hashList.begin(), hashList.end(), hash) == hashList.end()) {
            hashList.push_back(hash);
       } 
    } 
    cout << hashList.size();
    return 0;
}