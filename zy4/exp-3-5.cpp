#include <bits/stdc++.h>
#include <streambuf>
#include <vector>
using namespace std;

const int MOD = 128;

struct dsu {
    std::vector<int> pa;

    explicit dsu(int size) : pa(size) {
        std::iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        return pa[x] == x ? x : (pa[x] = find(pa[x]));
    }

    void unite(int x, int y) {
        pa[find(x)] = find(y);
    }
};

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

	void kruskal() {
		vector<int> e(n);
		for (int i = 1; i <= n; i++)
			e[i-1] = mat[x]
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

	int x, y, w;
	while (true) {
		cin >> p1;
		if (p1 == 'n')
			break;
		x = p1 - '0';
		cin >> y >> w;
		g.mat[x][y] =
		    g.mat[y][x] = w;
	}

	return 0;
}

/*
9
1 2 3 4 5 6
1 5 5
1 2 12
1 4 8
2 5 15
2 3 20
3 5 10
3 6 9
4 5 6
4 6 4
5 6 8
n
*/