#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long

int n, m;

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

struct edge {
	int u,v,w;
};
edge e[mod] {};
dsu d(mod);
vector<int> out;

bool f(edge &a, edge &b) {
	return a.w < b.w;
}

void kruskal() {
	sort(e, e + m, f);

	int cnt = 0;
	int t1, t2;
	for (int i = 0; i < m; i++) {
		t1 = d.find(e[i].u);
		t2 = d.find(e[i].v);
		if (t1 == t2)
			continue;


		out.push_back(i);
		d.unite(t1, t2);

		if (++cnt == n-1)
			break;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 


    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	cin >> e[i].u >> e[i].v >> e[i].w;
    }

    kruskal();
    int sum = 0;
    cout << "_______________________" << endl;
    for (auto it : out) {
    	sum += e[it].w;
    	cout << e[it].u << " => " << e[it].v << endl;
    }
    cout << "sum of weight: " << sum << endl;

	return 0;
}


/* 
6 10
1 2 12
1 5 5
1 4 8
2 5 15
2 3 20
3 5 10
4 5 6
4 6 4
5 6 8
6 3 9*/

// 12 + 5 + 6 + 4 + 20 + 9