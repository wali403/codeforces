#include <bits/stdc++.h> 
#include <queue>
#include <vector>
using namespace std;

#define mod (1001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int n, m;
int a, b, c;
vector<P> g[mod];
bool vis[mod] {};
int dijkstra(int start, int end) {
    vector<int> dist(mod, INT_MAX);
    memset(vis, 0, sizeof(vis));

    //注意这里的p.x是权值
    priority_queue<P, vector<P>, greater<P>> q; // 小根堆

    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        P current = q.top();
        q.pop();
        int u = current.y;

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &it : g[u]) {
            int v = it.x;
            int weight = it.y;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                q.push({dist[v], v});
            }
        }
    }

    return dist[end] == INT_MAX ? -1 : dist[end]; 
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	
	while (true) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}

		for (int i = 0; i < n; i++)
			g[i].clear();

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}

		cout << dijkstra(1, n) << endl;

	} 

	return 0;
}