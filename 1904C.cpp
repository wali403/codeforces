#include <bits/stdc++.h>
#include <iterator>
#include <set>
using namespace std;

const int mod = 2e3 + 10;
typedef unsigned long long ll;
#define x first
#define y second
typedef pair<int, int> P;

multiset<ll> s;

int n;
ll k;

void solve() {

	cin >> n >> k;

	s.clear();

	ll tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}

	if (k >= 3) {
		cout << 0 << endl;
		return;
	}
	ll x, y;
	ll mi = 1e18+1;
	if (k == 1) {
		for (auto it = s.begin(); it != prev(s.end()); it++) {
			x = *it, y = *next(it);
			if (y - x < mi) {
				mi = y - x;
			}
		}
		cout << mi << endl;
		return;
	}

	ll ans = 1e18+1;
	for (auto it = s.begin(); it != s.end(); it++) {
		for (auto yt = s.begin(); yt != it; yt++) {
			ll v = *it - *yt;
			ans = min(ans, v);
			auto a = s.lower_bound(v);
			auto b = s.upper_bound(v);

			ans = min(ans, min(*a-v, v-*b));
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}