#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

struct node {
	node *lch, *rch;
	char c;
	node(char _c) : lch(nullptr), rch(nullptr), c(_c) 
		{}
};

node* f() {
	char c;
	cin >> c;
	if (c != '@') {
		node *root = new node(c);
		root->lch = f();
		root->rch = f();
		return root;
	}
	return nullptr;
}

void dfs_pre(node *p) {
	if (!p)
		return;

	cout << p->c << ' ';
	dfs_pre(p->lch);
	dfs_pre(p->rch);
}

void dfs_in(node *p) {
	if (!p)
		return;

	dfs_in(p->lch);
	cout << p->c << ' ';
	dfs_in(p->rch);
}

void dfs_post(node *p) {
	if (!p)
		return;

	cout << p->c << ' ';
	dfs_post(p->lch);
	dfs_post(p->rch);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    //ABD@F@@@CE@@@
	node *root = f();
	
    dfs_pre(root);
    cout << endl;
    dfs_in(root);
    cout << endl;
    dfs_post(root);
	return 0;
}