#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string a, b;
	cin >> a >> b;

	int l = 0, r = 0;
	for (int i = 0; i < b.size(); i++) {
		while (r < a.size() && a[r] != b[i]) {
			r++;
		}
		if (a[r] == b[i]) {
			//在后面可以找到 一样的字符
			if ((r - l - 1) % 2 == 0 || r == l) {
				//如果之间的字符数刚好为偶数
				l = r;
				r++;
				continue;
			} else {
				//否则说明前一个字符的位置找错了
				//继续在之间找，是否有同样的字符可以使得间隔为偶数
				i--;
				l++;
				continue;
				/*bool ok = false;
				while (l < r) {
					l++;
					cout << "a[l] = " <<a[l] << endl;
					cout << "b[i-1] = " << b[i-1] << endl;
					cout << "l = " << l << endl;
					cout << "r = " << r << endl;

					if (a[l] == b[i-1] && (r-l-1) % 2 == 0) {
						ok = true;
						cout << "ok " << endl;
						i--;
						break;
					}
				}
				if (!ok) {
					cout << "NO" << endl;
					return;
				}*/
			}
		}
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}