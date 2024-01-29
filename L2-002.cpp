#include <bits/stdc++.h> 

using namespace std;

#define mod (100001)
#define ll long long

struct node {
	int addr;
	int value;
	int next;
};

node d[mod] {};
list<node*> l;
list<node*> l2;
list<node*> l3;
int root, n, root_i;

void traverse_insert(node *p) {
	l.push_back(p);

	if (p->next == -1)
		return;

	for (int i = 0; i < n; i++) {
		if (d[i].addr == p->next)
			return traverse_insert(&d[i]);
	}
}
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    
    cin >> root >> n;
    for (int i = 0; i < n; i++) {
    	cin >> d[i].addr >> d[i].value >> d[i].next;
    	if (d[i].addr == root) {
    		root_i = i;
    	}
    }
    traverse_insert(&d[root_i]);

    map<int, int> m;
    int ia;

    node *p, *p3;
	for (auto it = l.begin(); it != l.end(); it++) {
		p = (*it);
		ia = abs(p->value);

    	m[ia]++;

    	if (m[ia] > 1) {
    		if (it != prev(l.end())) {
	    		p3 = *prev(it);
	    		p3->next = p->next;
    		} else {
    			p->next = -1;
    		}
	    	l3.push_back(p);
    	} else {
    		l2.push_back(p);
    	}
	}

    l2.back()->next = -1; //keep
    l3.back()->next = -1; //delete

    for (const auto& element : l2) {
    	if (element->next == -1)
	    	printf("%05d %d -1", element->addr, element->value);
	    else
    		printf("%05d %d %05d", element->addr, element->value, element->next);
    	if (!l.empty())
    		printf("\n");
    	else if (element != l2.back())
    		printf("\n");
    }

    for (const auto& element : l3) {
    	if (element->next == -1)
	    	printf("%05d %d -1", element->addr, element->value);
	    else
    		printf("%05d %d %05d", element->addr, element->value, element->next);
    	if (element != l3.back())
    		printf("\n");
    }

	return 0;
}