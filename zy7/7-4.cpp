#include <bits/stdc++.h> 
using namespace std;

int shellSort(int* arr, int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
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

    shellSort(v, n);

    for (int i =0; i < n;i++)
        cout << v[i] << ' ';


    return 0;
}