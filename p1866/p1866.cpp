#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long C_m_n(int m, int n) {
    long long res = 1;
    while (n--) {
        res *= m;
        res %= 1000000007;
        m--;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        int num;
        cin >> num;
        pq.push(num);
    }
    map<int, int> m;
    while (!pq.empty()) {
        int num = pq.top();
        pq.pop();
        if (m.find(num) == m.end()) {
            m[num] = 1;
        } else {
            m[num]++;
        }
    }
    int leftSpace = 0;
    long long res = 1;
    int preAsked = 0;
    for (auto pair: m) {
        int count = pair.second;
        int asked = pair.first;
        leftSpace += asked - preAsked;
        if (count > leftSpace) {
            cout << 0;
            return 0;
        }
        res *= C_m_n(leftSpace, count);
        res %= 1000000007;
        leftSpace -= count;
        preAsked = asked; 
    }
    cout << res;
    return 0;   
}