#include <iostream>
#include <algorithm>

#include <vector>

int main() {

	// where d is some positive number, common for all lanterns.
	int num; long long length;
	using namespace std;
	cin >> num >> length;

	vector<long long>v;

	//locations for lanterns 0-10^9
	for (int i = 0; i < num; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	// ascending
	std::sort(v.begin(), v.end());

	long long max_distance = std::max(v[0], length - v[v.size() - 1]) * 2; //head and end
	for (int i = 0; i < num - 1; i++) {
		max_distance = std::max(max_distance, v[i + 1] - v[i]);
	}

	cout.precision(2);
	cout << std::fixed << (double)max_distance / 2.0;
	return 0;
}	