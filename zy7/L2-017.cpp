#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
int v[mod];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	sort(v+1, v+n+1);
	ll p1 = 0, p2 = 0;

	int mid = n/2;
	cout << "Outgoing #: " << (n % 2 == 0 ? mid : mid+1) << endl;
	cout << "Introverted #: " << mid << endl;

	for (int i = 1; i <= mid; i++)
		p1 += v[i];
	for (int i = mid+1; i <= n; i++)
		p2 += v[i];
	cout << "Diff = " << abs(p1-p2);

	return 0;
}