#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int SZ = 100001;

struct node {
	char v;
	node *lch, *rch;
	node(char value) : v(value), lch(nullptr), rch(nullptr) {}
};

int lch[SZ] {}, rch[SZ] {};
string sq;

node* gen(int &i) {
	if (sq[i] == '@') {
		i++;
        return nullptr;
    }
    node* root = nullptr;
    root = new node(sq[i++]);
    root->lch = gen(i);
    root->rch = gen(i);
    return root;
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

bool dfs_sch(node *root, char trg) {
	if (!root)
		return false;

	if (root->v == trg) {
		cout << "lch:" << (root->lch ? root->lch->v : '^') << endl;
		cout << "rch:" << (root->rch ? root->rch->v : '^') << endl;
		return true;
	}
	if (dfs_sch(root->lch, trg))
		return true;
	if (dfs_sch(root->rch, trg))
		return true;
	return false;
}

int main() {    

    //ABD@F@@@CE@@@

    cout << "type order:";
   	std::getline(cin, sq);

   	int tmp = 0;
   	node *tree = gen(tmp);

   	cout << "pre:";
   	dfs_pre(tree);
   	cout << endl;

   	cout << "in:";
   	dfs_in(tree);
   	cout << endl;

   	cout << "post:";
   	dfs_post(tree);
   	cout << endl;

   	char in;
   	for(;;) {
   		cout << "Type the node you want to check ($ to end)";
   		cin >> in;
   		if (in == '$')
   			break;
   		if (!dfs_sch(tree, in))
   			cout << "node not found." << endl;
   	}
	return 0;
}

/*
ABHFDECKG
HBDFAEKCG
*/