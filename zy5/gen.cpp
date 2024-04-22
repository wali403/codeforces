#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n = 30, m = 100;
	cout << n << ' ' << m << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << 'y';
		}
		cout << endl;
	}

	return 0;
}