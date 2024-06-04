#include <bits/stdc++.h> 
#include <variant>
using namespace std;

void bubble_sort(int* array, int size) {
	int cache;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				cache = array[j - 1];
				array[j - 1] = array[j];
				array[j] = cache;
			}
		}
		cout << "round " << i << endl;
		for (int j =0; j < size; j++) {
	        cout << array[j] << ' ';
	    }
	    cout << endl;
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

    bubble_sort(v, n);

    for (int i =0; i < n;i++) {
        cout << v[i] << ' ';
    }

	return 0;
}