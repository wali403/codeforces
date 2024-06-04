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

node* gen(int &i) {
    if (sq[i] == '@') {
        i++;
        return nullptr;
    }
    node* root = new node(sq[i++]);
    root->lch = gen(i);
    root->rch = gen(i);
    return root;
}

void dfs_pre_nonrec(node *root) {
    if (!root) return;
    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* curr = s.top();
        s.pop();
        cout << curr->v;
        if (curr->rch) s.push(curr->rch);
        if (curr->lch) s.push(curr->lch);
    }
}

void dfs_in_nonrec(node *root) {
    stack<node*> s;
    node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->lch;
        }
        curr = s.top();
        s.pop();
        cout << curr->v;
        curr = curr->rch;
    }
}

void dfs_post_nonrec(node *root) {
    if (!root) return;
    stack<node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->lch) s1.push(curr->lch);
        if (curr->rch) s1.push(curr->rch);
    }
    while (!s2.empty()) {
        cout << s2.top()->v;
        s2.pop();
    }
}

bool dfs_sch(node *root, char trg) {
    if (!root)
        return false;

    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* curr = s.top();
        s.pop();
        if (curr->v == trg) {
            cout << "lch:" << (curr->lch ? curr->lch->v : '^') << endl;
            cout << "rch:" << (curr->rch ? curr->rch->v : '^') << endl;
            return true;
        }
        if (curr->rch) s.push(curr->rch);
        if (curr->lch) s.push(curr->lch);
    }
    return false;
}

int main() {

    cout << "type order:";
    std::getline(cin, sq);

    int tmp = 0;
    node *tree = gen(tmp);

    cout << "pre:";
    dfs_pre_nonrec(tree);
    cout << endl;

    cout << "in:";
    dfs_in_nonrec(tree);
    cout << endl;

    cout << "post:";
    dfs_post_nonrec(tree);
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

/*ABHFDECKG
HBDFAEKCG*/