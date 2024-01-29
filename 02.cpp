#include <algorithm>
#include <bits/stdc++.h> 
#include <string>
#include <vector>
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    vector<string> s;
	string tmp;
	while (cin.peek() != '\n') {
		cin >> tmp;
		s.push_back(tmp);
	}
	reverse(s.begin(), s.end());
	for (auto it : s)
		cout << it << ' ';

	return 0;
}