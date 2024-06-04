#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)

int fre[256] {};
int lch[mod], rch[mod];

int v[SZ], len = 0;

//建堆
void heaplify(int num) {
	v[++len] = num;
	int pos = len;
	while (pos > 1) {
		// 上滤，大根堆
		if (v[pos] < v[pos / 2])  {
			swap(v[pos], v[pos / 2]);
 			pos /= 2; //往上
			continue;
		}
		break;
	}
}


int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string s;
	cin >> s;
	for (auto it :s)
		fre[it]++;
	sort(fre, fre + 256, greater<int>);

	int i = 0;
	while (pre[i]) {
		heaplify(fre[it]);
	}

	return 0;
}