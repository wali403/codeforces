#include <bits/stdc++.h>
using namespace std;

struct node {
    node *lch, *rch;
    char c;
    int freq;
    node(char _c, int _freq) : lch(nullptr), rch(nullptr), c(_c), freq(_freq) {}
    node(node* _lch, node* _rch) : lch(_lch), rch(_rch), c('\0'), freq(_lch->freq + _rch->freq) {}
};

struct compare {
    bool operator()(node* l, node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->lch && !root->rch) {
        huffmanCode[root->c] = code;
    }

    generateCodes(root->lch, code + "0", huffmanCode);
    generateCodes(root->rch, code + "1", huffmanCode);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    priority_queue<node*, vector<node*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        node* left = pq.top(); pq.pop();
        node* right = pq.top(); pq.pop();
        node* combined = new node(left, right);
        pq.push(combined);
    }

    node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    string encodedString = "";
    for (char c : s) {
        encodedString += huffmanCode[c];
    }

    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "out: " << encodedString << endl;

    return 0;
}
