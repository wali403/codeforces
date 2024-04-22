#include <bits/stdc++.h> 
using namespace std;

struct node {
	char v;
	node *lch, *rch;
	node(char i): v(i), lch(nullptr), rch(nullptr) {}
};

void dfs(node *root, int &cnt) {
	if (!root) {
		return;
	}

	if (!root->lch && !root->rch) {
		cnt++;
	} else {
		dfs(root->lch, cnt);
		dfs(root->rch, cnt);
	}
}

string bo;
node *build(int index) {
	if (index > bo.size())
		return nullptr;
	if (bo[index] == '@')
		return nullptr;
	node *root = new node(bo[index]);
	root->lch = build(index * 2);
	root->rch = build(index * 2 + 1);

	return root;
}

int main() {    
    cout << "type in bfs order:";
    cin >> bo;
    bo.insert(0, "-");

    node* root = build(1);

    int cnt = 0;

    dfs(root, cnt);
    cout << "leaf:" << cnt;
    cout << endl;
	return 0;
}

//ABCD@E@@F@@@@