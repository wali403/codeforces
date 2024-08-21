#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n, m;
	scanf("%d%d",&n,&m);

	int cur = 1;
	bool f = true;
	for (int i = cur; i <= m; i++) {
		cur += f ? 1 : -1;
		if (cur == n || cur == 1)
			f ^= 1;
	}
	printf("%d\n", cur);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}