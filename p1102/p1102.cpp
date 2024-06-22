#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;


int main() {
    long long N, C;
    cin >> N >> C;
    priority_queue<unsigned int> pq;
    while (N--) {
        unsigned int input;
        cin >> input;
        pq.push(input);
    }
    vector<unsigned int> list;
    while (!pq.empty()) {
        list.push_back(pq.top());
        pq.pop();
    }
    int left, right;
    left = right = 0;
    long long  res = 0;
    while (right < list.size()) {
        long long diff = list[left] - list[right];
        if (diff == C) {
            long long leftAccum = 1;
            long long rightAccum = 1;
            while (left < right && list[left + 1] == list[left]) {
                leftAccum++;
                left++;
            }
            while (right < list.size() && list[right + 1] == list[right]) {
                rightAccum++;
                right++;
            }
            res += leftAccum * rightAccum;
            left++;
            right++;
        } else if (diff > C) {
            left++;
        } else {
            right++;
        }
    }
    cout << res;
    return 0;
}