#include <bits/stdc++.h>
using namespace std;

template<class T>
class Tri {
private:
	const int SZ = 128;
	struct st {
		int x, y;
		T v;
		//st(int p1, int p2, T value): x(p1), y(p2), v(value) {};
	};

	st* t;
	int len;
public:
	Tri() {
		t = new st[SZ];
		len = 0;
	}
	~Tri() {
		delete[] t;
	}
	void push(int x, int y, T v) {
		if (len >= SZ)
			return;

		t[len].x = x;
		t[len].y = y;
		t[len].v = v;
		len++;

	}
	void show() {
		for (int i = 0; i < len; i++) {
			cout << "E(" << t[i].x << ',' << t[i].y << ") = " << t[i].v;
			cout << endl;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[4][5] = {
		{0, 23, 0, 14, 0},
		{12, 0, 0, 0, 0},
		{0, 0, 45, 6, 0},
		{16, 0, 0, 0, 27}
	};

	Tri<int> list;
	cout << "a = " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++){
			cout << a[i][j] << ' ';
			if (a[i][j])	
				list.push(i,j, a[i][j]);
		}
		cout << endl;
	}

	cout << endl;
	cout << "Tri list:" << endl;

	list.show();
	return 0;
}