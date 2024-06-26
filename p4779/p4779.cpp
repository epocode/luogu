#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <queue>
using namespace std;

int head[100010];
int cnt = 0;
int ans[100010];
bool vis[100010];
struct Edge
{
    int to;
    int next;
    int weight;
} edge[1000000];

void addEdge(int u, int v, int weight)
{
    
    cnt += 1;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].weight = weight;
    head[u] = cnt;
}

struct Priority {
    int dis;
    int index;
    bool operator < (const Priority x) const {
        return this->dis > x.dis;
    }
};

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = INT32_MAX;
        vis[i] = false;
    }
    priority_queue<Priority> pq;
    ans[s] = 0;
    pq.push((Priority){0, s});
    while (!pq.empty()) {
        int curIndex = pq.top().index;
        pq.pop();
        if (vis[curIndex]) {
            continue;
        }
        vis[curIndex] = true;
        for (int edgeIndex = head[curIndex]; edgeIndex != 0; edgeIndex = edge[edgeIndex].next) {
            int temp = ans[curIndex] + edge[edgeIndex].weight;
            if (temp < ans[edge[edgeIndex].to]) {
                ans[edge[edgeIndex].to] = temp;
                               if (!vis[edge[edgeIndex].to]) {
                    pq.push((Priority){temp, edge[edgeIndex].to});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

// int main()
// {
//     int n, m, s;
//     ifstream infile("P4779_1.in");
//     if (!infile.is_open())
//     {
//         std::cerr << "Failed to open file" << std::endl;
//         return 1;
//     }

//     infile >> n >> m >> s;
//     vector<unordered_map<int, int>> graph(n + 1, unordered_map<int, int>());
//     while (m--)
//     {
//         int u, v, w;
//         infile >> u >> v >> w;
//         if (graph[u].find(v) != graph[u].end()) {
//             cout << u << "to" << v << endl;
//         }
//         graph[u][v] = w;
//     }
//     vector<int> shortestDistance(n + 1, INT32_MAX);
//     vector<bool> visited(n + 1, false);
//     shortestDistance[s] = 0;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push(pair<int, int>(0, s));
//     while (!pq.empty())
//     {
//         int index = pq.top().second;
//         pq.pop();
//         if (visited[index]) {
//             continue;
//         }
//         visited[index] = true;
//         for (pair<int, int> neighbor: graph[index]) {
//             int temp = shortestDistance[index] + neighbor.second;
//             if ( temp < shortestDistance[neighbor.first]) {
//                 shortestDistance[neighbor.first] = temp;
//                 pq.push(pair<int, int>(temp, neighbor.first));
//             }
//         }
//     }
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << shortestDistance[i] << " ";
//     // }
//     return 0;
// }
