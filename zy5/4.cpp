#include <bits/stdc++.h> 
using namespace std;

const int SZ = 100001;

struct node {
	char v;
	node *lch, *rch;
	node(char value) : v(value), lch(nullptr), rch(nullptr) {}
};

int lch[SZ] {}, rch[SZ] {};

string sq;
node* dfs(int root) {

	if (root >= sq.size())
		return nullptr;

	node *r = new node(sq[root-1]);

	r->lch = dfs(root * 2);
	r->rch = dfs(root * 2 + 1);
	return r;
}

void dfs_pre(node *root) {

	if (!root)
		return;

	cout << root->v;
	dfs_pre(root->lch);
	dfs_pre(root->rch);
}

void dfs_in(node *root) {

	if (!root)
		return;

	dfs_pre(root->lch);
	cout << root->v;
	dfs_pre(root->rch);
}

void dfs_post(node *root) {

	if (!root)
		return;

	dfs_pre(root->lch);
	dfs_pre(root->rch);
	cout << root->v;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

   	std::getline(cin, sq);

   	node* tree = dfs(1);

   	dfs_pre(tree);

	return 0;
}

/*
ABHFDECKG
HBDFAEKCG
*/