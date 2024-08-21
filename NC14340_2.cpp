#include <bits/stdc++.h> 
#include <queue>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

P df[8] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{1, -1},
	{ -1, -1},
	{ -1, 1},
	{ -1, 0},
	{1, 1},
};

P di[4] = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1}
};

int n,m;

int s1,s2,e1,e2;

char v[50][50];
bool vis[50][50];
int g[50][50];

struct N {
	int x,y,z;
	N(int p1, int p2, int p3): x(p1), y(p2), z(p3) {}
};

queue<N> q;
void bfs1() {

	memset(vis, 0, sizeof(vis));
	memset(g, 0, sizeof(g));

	while (!q.empty()) {
		q.pop();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == '*') {
				q.emplace(i, j, 0);
				g[i][j] = 0;
				vis[i][j] = true;
				break;
			} 
		}
	}

	N cur(0,0,0);
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int p1 = cur.x + df[i].x, p2 = cur.y + df[i].y;
			if (p1 < 1 || p1 > n || p2 < 1 || p2 > m)
				continue;
			if (vis[p1][p2])
				continue;

			vis[p1][p2] = true;
			if (v[p1][p2] == 'E') {
				q.emplace(p1, p2, g[p1][p2] = cur.z + 2);
			} else {
				q.emplace(p1, p2, g[p1][p2] = cur.z + 1);
			}
		}
	}
}

void bfs2() {
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		q.pop();
	}

	q.emplace(s1,s2,0);

	N cur(0,0,0);
	while (!q.empty()) {
		cur = q.front();	
		q.pop();

		if (cur.x == e1 && cur.y == e2) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int p1 = cur.x + di[i].x, p2 = cur.y + di[i].y;
			if (p1 < 1 || p1 > n || p2 < 1 || p2 > m)
				continue;
			if (vis[p1][p2])
				continue;
			if (v[p1][p2] == '#')
				continue;
			if (cur.z >= g[p1][p2])
				continue;

			vis[p1][p2] = true;
			q.emplace(p1, p2, g[p1][p2] = cur.z + 1);
		}
	}

	if (cur.x == e1 && cur.y == e2) {
		cout << cur.z << endl;
	} else {
		cout << "T_T" << endl;
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)  {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			switch (v[i][j]) {
				case 'S':
				s1 = i, s2 =j;
				break;
				case 'E':
				e1 = i, e2 = j;
				break;
			}
		}
	}

	bfs1();
	bfs2();
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();	

	return 0;
}