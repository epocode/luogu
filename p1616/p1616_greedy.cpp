#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Thing {
    long long cost;
    long long value;
    double price;
};

struct cmp {
    bool operator()(const Thing& a, const Thing& b) const {
        return a.price < b.price;
    }
};
int main() {
    int t, m;
    cin >> t >> m;
    priority_queue<Thing, vector<Thing>, cmp> pq;
    for (int i = 1; i <= m; i++) {
        Thing input;
        cin >> input.cost >> input.value;
        input.price = (double)input.value / input.cost;
        pq.push(input);
    }
    long long res = 0;
    while (t && !pq.empty()) {
        Thing thing = pq.top();
        pq.pop();
        if (thing.cost > t) {
            continue;
        } 
        long long count = t / thing.cost;
        res += (long long)count * thing.value;
        t = t - count * thing.cost;
    }
    cout << res;
    return 0;
}