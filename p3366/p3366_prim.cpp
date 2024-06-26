#include <iostream>
#include <queue>

using namespace std;

int head[100010];
int visited[100010];
int dis[100010];
struct Edge{
    int to;
    int next;
    int weight;
} edges[1000000];
int cnt = 0;
void addEdge(int u, int v, int weight) {
    cnt++;
    edges[cnt].next = head[u];
    edges[cnt].to = v;
    edges[cnt].weight = weight;
    head[u] = cnt;
}
long long prim(int start, int size) {
    int index = start;
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, index));
    int cnt = 0;
    long long res = 0;
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int index = pair.second;
        if (visited[index]) {
            continue;
        } 
        visited[index] = true;
        for (int i = head[index]; i; i = edges[i].next) {
            int u = index;
            int v = edges[i].to;
            int weight = edges[i].weight;
            if (!visited[v] && weight < dis[v]) {//注意必须添加visited判断条件
                dis[v] = weight;
                pq.push(make_pair(weight, v));
            }
        }
        cnt++;
        res += dis[index];
        if (cnt == size) {
            return res;
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        head[i] = 0;
        visited[i] = false;
        dis[i] = INT32_MAX;
    }
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dis[1] = 0;
    long long res =  prim(1, N);
    if (res == -1) {
        cout << "orz";
    } else {
        cout << res;
    }
    return 0;
}