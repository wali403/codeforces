#include <bits/stdc++.h>
using namespace std;

const int MOD = 128;

template<class T>
class G {
public:
	int n;
	int mat[MOD][MOD];
	bool vis[MOD];
	T value[MOD];

	G() {
		memset(mat, 0, sizeof(mat));
		memset(value, 0, sizeof(value));
	}

	void bfs(int x) {
		memset(vis, 0, sizeof(vis));

		queue<int> q;
		q.push(x);
		vis[x] = true;
		int cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			cout << value[cur] << ' ';

			for (int j = 1; j <= n; j++) {
				if (mat[cur][j] && !vis[j]) {
					vis[j] = true;
					q.push(j);
				}
			}
		}
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	G<int> g;
	char p1;

	cin >> g.n;

	for (int i = 1; i <= g.n; i++) {
		cin >> g.value[i];
	}

	int x, y;
	while (true) {
		cin >> p1;
		if (p1 == 'n')
			break;
		x = p1 - '0';
		cin >> y;
		g.mat[x][y] =
		    g.mat[y][x] = 1;
	}

	g.bfs(1);
	return 0;
}

/*
9
1 2 3 4 5 6 7 8 9
1 2
1 5
2 3
2 9
3 4
3 6
3 8
5 7
n
*/