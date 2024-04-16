#include <bits/stdc++.h> 
using namespace std;

string pre, in;

int index;

struct node {
	char v;
	node *lch, *rch;
	node(char i): v(i), lch(nullptr), rch(nullptr) {}
};

void dfs(int l, int r, int &t, node* &root) {
	int id = -1;

	for (int i = l; i < r; i++) {
		if (in[i] == pre[t]) {
			id = i;
			break;
		}
	}

	if (id == -1)
		return;

	root = new node(in[id]);
	t++;

	if (id > l) {
		dfs(l, id, t, root->lch);
	}
	if (id < r) {
		dfs(id, r, t, root->rch);
	}
}

void dfs_post(node *root) {
	if (!root)
		return;
	dfs_post(root->lch);
	dfs_post(root->rch);
	cout << root->v;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> pre >> in;
    node *root;
    int t = 0;
   	dfs(0, pre.size(), t, root);

   	cout << "post order: ";
   	dfs_post(root);

	return 0;
}

/*
ABHFDECKG
HBDFAEKCG
*/