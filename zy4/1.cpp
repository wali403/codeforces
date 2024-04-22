#include <bits/stdc++.h> 
using namespace std;

int main() {    

	int a[2][3] {};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "Type: ";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	int b[3][2] {};

	cout << "a:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			b[i][j] = a[j][i];
		}
	}

	cout << "b:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}