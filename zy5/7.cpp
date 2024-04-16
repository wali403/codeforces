#include <bits/stdc++.h> 
#include <queue>
using namespace std;

struct node {
	char v;
	node *lch, *rch;
	node(char i): v(i), lch(nullptr), rch(nullptr) {}
};

string bo;
node *bfs() {
	queue<node*> q;
	q.push(new node(bo[0]));
	node* current;
	node* root = q.front();
	int index = 1;

    while (!q.empty() && index < bo.size()) {
       	current = q.front();
        q.pop();

        if (index < bo.size() && bo[index] != '@') {
            current->lch = new node(bo[index]);
            q.push(current->lch);
        }
        index++;

        if (index < bo.size() && bo[index] != '@') {
            current->rch = new node(bo[index]);
            q.push(current->rch);
        }
        index++;
    }
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

    node* root = bfs();

    cout << "pre-order generated:";
    dfs(root);
    cout << endl;

    cout << "bfs order:";
    bfs_traverse(root);

	return 0;
}

// ABC@D@@