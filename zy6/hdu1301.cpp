#include <bits/stdc++.h>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<char, pair<char, int>> P;

vector<P> edges;

int pa[mod] {};

void init_dsu() {
	for (int i = 0; i < mod; i++) {
		pa[i] = i;
	}
}

int find(int x) {
	return pa[x] == x ? x : (pa[x] = find(pa[x]));
}

void unit(int x, int y) {
	pa[find(x)] = find(y);
}

bool cmp(P& a, P& b) {
	return a.y.y < b.y.y;
}

int kruskal() {
	int sum = 0;
	int p1, p2;
	for (auto &it : edges) {
		p1 = find(it.x);
		p2 = find(it.y.x);
		if (p1 != p2) {
			unit(p1, p2);
			sum += it.y.y;
		}
	}
	return sum;
}

bool work = true;
void solve() {
	int n;
	cin >> n;
	if (!n) {
		work = false;
		return;
	}
	edges.clear();
	init_dsu();

	char v; int es;
	char m; int w;
	for (int j = 0; j < n-1; j++) {
		cin >> v >> es;

		for (int i = 0; i < es; i++) {
			cin >> m >> w;
			edges.push_back({v, {m, w}});
		}
	}

	sort(edges.begin(), edges.end(), cmp);
	cout << kruskal() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (work)
		solve();

	return 0;
}
