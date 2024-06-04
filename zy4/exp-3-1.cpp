#include <bits/stdc++.h>
#include <functional>
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
		memset(vis, 0, sizeof(vis));
		memset(mat, 0, sizeof(mat));
		memset(value, 0, sizeof(value));
	}

	void dfs(int x) {
		cout << value[x] << ' ';
		for (int j = 1; j <= n; j++) {
			if (mat[x][j] && !vis[j]) {
				vis[j] = true;
				dfs(j);
				vis[j] = false;
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
/*
	for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++) {
			cout << g.mat[i][j] << ' ';
		}
		cout << endl;
	}*/

	g.vis[1] = true;
	g.dfs(1);
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