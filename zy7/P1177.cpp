#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define mod (100001)

ll n;
ll v[mod];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	cin >> n;
	for (int i = 0; i < n;i++)
		cin >> v[i];
	sort(v, v+n);
	for (int i = 0; i < n; i++) 
		cout << v[i] << ' ';

	return 0;
}