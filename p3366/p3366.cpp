#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

#define NODESIZE 100010
#define EDGESIZE 1000000

struct Edge{
    int u;
    int v;
    int weight;
    bool operator > (const Edge & edge) const {
        return this->weight > edge.weight;
    }
} edges[EDGESIZE];
int parent[NODESIZE];
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}
void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}
int main() {
    unordered_set<int> curNodes;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        pq.push(Edge{u, v, weight});
    }
    int curEdges = 0;
    long long res = 0;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        int u = edge.u;
        int v = edge.v;
        if (find(u) == find(v)) {
            continue;
        }
        int weight = edge.weight;
        res += weight;
        unite(u, v);
        curEdges++;
        if (curEdges == N - 1) {
            break;
        }
    }
    if (curEdges != N -1) {
        cout << "orz";
    } else {
        cout << res;
    }
    return 0;
}