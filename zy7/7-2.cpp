#include <bits/stdc++.h> 
using namespace std;

void ins_sort(int *arr, int sz) {

	for (int i = 1; i < sz; i++) {
		int k = arr[i];
		int j = i - 1;
		while (j >=0  && arr[j] > k) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = k;
	}	
}


int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	int *v = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ins_sort(v, n);

	for (int i =0; i < n;i++)
		cout << v[i] << ' ';
	return 0;
}