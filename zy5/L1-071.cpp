#include <bits/stdc++.h> 
using namespace std;

#define ll long long

map<ll, ll> tree;
ll tree_size;
ll cnt = 1;
/*
void setleaf(ll index) {
	if (index >= tree_size)
		return;

	if (index * 2 >= tree_size && index * 2 + 1 >= tree_size) {
		cout << "index " << index << "   cnt = " << cnt << endl;
		tree[index] = cnt++;
	} else {
		setleaf(index * 2);
		setleaf(index * 2 + 1);
	}
}*/

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	ll n, m;
	cin >> n >> m;

	tree_size = pow((ll)2, (ll)(n+1));
	//cout << "tree_size = " << tree_size << endl;
	//setleaf(1);

	vector<ll> ans(m);
	char c;

	ll ptr = 1;
	for (int i = 0; i < m; i++) {
		ptr = 1;
		for (int j = 0; j < n; j++) {
			cin >> c;
			ptr = ptr * 2;
			if (c == 'n')
				ptr++;
		}
		ans[i] = ptr - tree_size / 2 + 1;
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i];
		if (i != m -1)
			cout << endl;
	}
	return 0;
}