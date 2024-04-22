#include <bits/stdc++.h> 
#include <queue>
using namespace std;

struct node {
	char v;
	node *lch, *rch;
	node(char i): v(i), lch(nullptr), rch(nullptr) {}
};

string bo;
node *build(int index) {
	if (index > bo.size())
		return nullptr;
	if (bo[index] == '@')
		return nullptr;
	//cout << "bo[index] = " << bo[index] << endl;
	node *root = new node(bo[index]);
	root->lch = build(index * 2);
	root->rch = build(index * 2 + 1);

	return root;
}

void bfs_traverse(node* root) {
	queue<node*> q;
	q.push(root);

	node *current;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		cout << current->v;

		if (current->lch)
			q.push(current->lch);
		if (current->rch)
			q.push(current->rch);
	}
}

void dfs(node *root) {
	if (!root)
		return;
	cout << root->v;
	dfs(root->lch);
	dfs(root->rch);
}


int main() {    
    cout << "type in bfs order:";
    cin >> bo;
    bo.insert(0, "-");

    node* root = build(1);

    cout << "pre-order generated:";
    dfs(root);
    cout << endl;

    cout << "bfs order:";
    bfs_traverse(root);
	return 0;
}

//ABCD@E@@F@@@@