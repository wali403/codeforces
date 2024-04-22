#include <iostream>
using namespace std;

int n;
int tree[31];

void dfs(int i) {
    if (i > n)
        return;
    dfs(2 * i);
    dfs(2 * i + 1);
    cin >> tree[i];
}

int main() {
    cin >> n;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << ' ';
        cout << tree[i];
    }
    return 0;
}
