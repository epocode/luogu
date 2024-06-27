#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN  151
#define MAXM 5010
int graph[MAXN][MAXN];
int dfs[MAXN], low[MAXN], parent[MAXN];
struct Edge {
    int from;
    int to;
}edges[MAXM];
int cnt, depth, n, m;
void addEdges(int from, int to) {
    edges[++cnt].from = from;
    edges[cnt].to = to;
}
bool cmp(Edge a, Edge b) {
    return a.from != b.from ? a.from < b.from : a.to < b.to;
}

void targan(int index) {
    depth++;
    dfs[index] = low[index] = depth;
    for (int i = 1; i <= n; i++) {
        if (!graph[index][i]) {
            continue;
        }
        if (dfs[i] && i != parent[index]) {
            low[index] = min(dfs[i], low[index]);
        }
        if (!dfs[i]) {
            parent[i] = index;
            targan(i);
            low[index] = min(low[index], low[i]);
            if (low[i] > dfs[index]) {
                addEdges(min(index, i), max(index, i));
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from]= 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfs[i]) {
            targan(i);
        }
    }
    sort(edges + 1, edges + cnt + 1, cmp);
    for (int i = 1; i <= cnt; ++i) {
        cout << edges[i].from << " " << edges[i].to << endl;
    }
    return 0;
}