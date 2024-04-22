#include <bits/stdc++.h> 

using namespace std;

int a[4][5] = {
	{0, 23, 0, 14, 0},
	{12, 0, 0, 0, 0},
	{0, 0, 45, 6, 0},
	{16, 0, 0, 0, 27}
};

typedef pair<int, int> P;
map<P, int> um;

#define x first
#define y second

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int aa[5][4];
    for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			aa[i][j] = a[j][i];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (aa[i][j])
				um[{i, j}] = aa[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << aa[i][j] << ' ';
		}
		cout << endl;
	}

	for (auto it : um) {
		cout <<	"um(" << it.x.x << ',' << it.x.y << ") = " 
			<< it.y << endl;
	}

	return 0;
}