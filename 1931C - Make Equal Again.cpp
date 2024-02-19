#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;
	vector<vector<int>> v(t);

	for (int i = 0; i < t; i++) {
		cin >> n;
		v[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	int s, e, ptr1, ptr2;
	bool f1, f2;
	for (int i = 0; i < t; i++) {
		if (v[i].size() == 1)
			cout << 0;
		else {
			ptr1 = 0;
			ptr2 = v[i].size() - 1;
		
			s = v[i][ptr1];
			e = v[i][ptr2];
			f1 = f2 = true;

			while (f1 || f2) {
				if (v[i][ptr1] == s && ptr1 != v[i].size() - 1) {
					ptr1++;
				} else {
					f1 = false;
				}

				if (v[i][ptr2] == e && ptr2 != 0) {
					ptr2--;
				} else {
					f2 = false;
				}
			}

			if (s != e) {
				//减去从头/尾最大连续数的个数
				//cout << "mx " << max(ptr1, (int)v[i].size() - ptr2 - 1) << endl;
				cout << v[i].size() - max(ptr1, (int)v[i].size() - ptr2 - 1); 
			} else {
				cout << max(0, ptr2 - ptr1 + 1);
			}
		}
		
		if (i != t -1) 
			cout << endl;
	}

	return 0;
}