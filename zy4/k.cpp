#include <bits/stdc++.h> 
#include <vector>
using namespace std;

struct st {
	string name, id;
	bool flag;
	int m; //last req
    int xu;
};

bool cmp(st &a, st &b) {
    if (a.m == b.m) {
        return a.xu < b.xu;
    }
	return a.m < b.m;
}

unordered_map<string, st> um;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int d, p, t, s;
	cin >> d >> p;

	vector<vector<st>> ans(d);
	vector<st> extra;
	set<string> extra_rec;

	st ca;
	char c;
	int hour, minute;
	bool flag = false, leading ;

	int reTime = p * 1440;
	int curTime = 0;
	int gcnt = 0;

	int zero = 0;
	for (int i = 0; i < d; i++) {
		cin >> t >> s;

		gcnt = 0;
        int xxx = 0;
		for (int j = 0; j < t; j++) {
			flag = true;
			leading = true;
			zero = 0;

			cin >> ca.name >> ca.id >> ca.flag;
			cin >> hour >> c >> minute;
			
			if (gcnt >= s)
				continue;

			ca.m = hour*60+minute;
            ca.xu = xxx++;

			for (auto c : ca.id) {
				if (!isdigit(c)) {
					flag = false;
				} else if (c == '0' && leading) {
					zero++;
				} else {
					leading = false;
				}
			}

			if (ca.id.size() + zero != 18)
				continue;

			if (!flag)
				continue;

			if (ca.flag) {
				if (!extra_rec.count(ca.id)) {
					extra.push_back(ca);
					extra_rec.insert(ca.id);
				}
			}

			if (um.count(ca.id)) {
				st &trg = um[ca.id];
				if (curTime - trg.m < reTime) {
					continue;
				}

				ans[i].push_back(ca);
				gcnt++;
			} else {
				um[ca.id] = ca;
				ans[i].push_back(ca);
				gcnt++;
			}
		}
		sort(ans[i].begin(), ans[i].end(), cmp);
		curTime += 1440;
	}

	for (int i = 0; i < d; i++) {
		//cout << "day " << i << endl;
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j].name << ' ' << ans[i][j].id  << endl; 
		}
	}

	for (int i = 0; i < extra.size(); i++) {
		cout << extra[i].name << ' ' << extra[i].id;
		
		cout << endl;
	}

	return 0;
}