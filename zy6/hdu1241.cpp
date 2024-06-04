#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int n, m;
char mp[100][100];
bool work = true;

P dir[8] = {
	{0, 0},
	{0, 1},
	{0, -1},
	{1, 0},
	{1, -1},
	{-1, 1},
	{-1, -1},
	{1, 1}
};

void dfs(int x, int y) {
	if (x < 0 || x > n || y < 0 || y > m) 
		return;
	int p1, p2;
	for (int i = 0; i < 8; i++) {
		p1 = x+dir[i].x, p2 = y+dir[i].y;
		if (mp[p1][p2] == '@') {
			mp[p1][p2] = '*';
			dfs(p1, p2);
		}
	}
}

void solve() {
	cin >> n >> m;

	int ans= 0;

	if (n == m && !n) {
		work = false;
		return;
	}

	for (int i = 0; i <n;i++) {
		for (int j=0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i <n;i++) {
		for (int j=0; j < m; j++) {
			if (mp[i][j] == '@') {
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (work)
		solve();

	return 0;
}