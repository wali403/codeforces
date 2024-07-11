#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

const int MX = 10;
int v[MX][MX] {};
int v2[MX][MX] {};
int main() {    

    cout << "2 rows and 3 columns: " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			v2[j][i] = v[i][j];
 		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << v2[i][j] << ' ';
 		}
 		cout << endl;
	}

	return 0;
}