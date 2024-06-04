#include <bits/stdc++.h>
using namespace std;

#define mod 256
#define x first
#define y second
typedef pair<int, int> P;

vector<P> adj[mod]; // 邻接表
bool vis[mod]; // 如果vis[i]==true那么节点i在MST中
int dis[mod]; // MST中的权值
int n;

int minKey() {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!vis[v] && dis[v] < min)
            min = dis[v], min_index = v;
    return min_index;
}

int prim() {
    int sum = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // 从第一个节点开始
    dis[0] = 0;

    for (int count = 0; count < n; count++) {
        // 从未在MST中的顶点集中选择一条权值最小的
        int u = minKey();
        if (u == -1) break; // 没节点可选

        //把节点加到mst里面
        vis[u] = true;
        sum += dis[u];

        // Update dis value of the adjacent vertices of the picked vertex
        for (auto &p : adj[u]) {
            int v = p.x;
            int weight = p.y;
            if (!vis[v] && weight < dis[v]) {
                dis[v] = weight;
            }
        }
    }
    return sum;
}

bool work = true;

void solve() {
    cin >> n;
    if (n == 0) {
        work = false;
        return;
    }

    for (int i = 0; i < mod; i++)
        adj[i].clear();

    char v; 
    int es;
    char m; 
    int w;
    for (int j = 0; j < n-1; j++) {
        cin >> v >> es;
        int u = v - 'A';

        for (int i = 0; i < es; i++) {
            cin >> m >> w;
            int v = m - 'A';
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // 无向图
        }
    }
    cout << prim() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (work)
        solve();

    return 0;
}
