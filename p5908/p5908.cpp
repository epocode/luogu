#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> graph(n+1);
    
    for (int i = 0; i < n - 1; i++)
    {
        int src, tgt;
        cin >> src >> tgt;
        graph[src].push_back(tgt);
        graph[tgt].push_back(src);
    }
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(1);
    int curD = 0;
    int res = 0;
    while (!q.empty() && curD <= d)
    {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curNode = q.front();
            q.pop();
            if (visited[curNode]) {
                continue;
            }
            visited[curNode] = true;
            if (curNode != 1) {
                res++;
            }
            for (int neighbor: graph[curNode]) {
                q.push(neighbor);
            }
        }
        curD++;
        
    }
    cout << res;
    return 0;
}